/***********************************************************************
* Program:
*    Project 1, Procedural Chess
*    Brother Sloan, CS165
* Author:
*    Larry Dewey
* Summary: 
*    This program lets two people play a very simple game of chess. It
*    does not currently stick to the rules normally implemented in chess
*    but is mainly for testing purposes. 
* 
*    Estimated:  4.0 hrs   
*    Actual:     20.0 hrs
*      The hardest thing for me about this project was getting the display
*      to work properly. There were so many glitches with testBed, that it
*      was very frustrating, and I haven't gotten it to work right still.
*      I also still couldn't get the file to read properly.  
************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <stdlib.h>
using namespace std;

// make it easier to handle the output of the display.
#define WHITEWHITE "\E[31;47m"
#define WHITEBLACK "\E[30;47m"
#define BLACKWHITE "\E[37;41m"
#define BLACKBLACK "\E[30;41m"

// Comment out to remove debugging.
#define DEBUG

#ifdef DEBUG
#define Debug(x)x
#else
#define Debug(x)
#endif

// I decided to use integers instead of characters. 
struct Position
{
   int R;
   int c;
};

struct Move
{
   string text;
   char piece;
   Position source;
   Position dest;
   bool capture;
   bool castleK;
   bool castleQ;
};

void initialize(char board[][8]);
void display(char board[][8], bool simple);
void read(vector < string > &moves, char board[][8], bool simple);
void interact(vector < string > &moves, char board[][8]);
inline bool parse(Move &move, char board[][8], string &errorMessage);
void execute(Move &move, char board[][8]);
void write(vector < string > &moves);


/**********************************************************************
* int main() is the main portion of the program, and it is the driving 
* force behind the scenes.    
***********************************************************************/
int main()
{
   // create the vector for holding all our moves
   vector < string > moves;

   char board[8][8];
   initialize(board);
   display(board, false);
   interact(moves, board);

   return 0;
}

/**********************************************************************
* INITIALIZE
*    This will display the board as it starts out, fresh and clean so 
*    the user has a nice new game to play.
***********************************************************************/
void initialize(char board[][8])
{
   char tempBoard[8][8] = {
      {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
      {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
      };
   for (int i = 0; i < 8; i++)
   {
      for (int j = 0; j < 8; j++)
      {
         board[i][j] = tempBoard[i][j];
      }
   }
}

/**********************************************************************
* DISPLAY
*    Pretty straightforward, this will display the current board 
*    configuration to the screen.        
***********************************************************************/
void display(char board[][8], bool simple)
{
   // declare variables
   bool blackSquare;
   bool blackPiece;
   char tempPiece;

   // only display the simple version if that's all the user wants
   if (simple)
   {
      cout << "  ";
      for (char c = 'a'; c < 'i'; c++)
         cout << c;

      cout << endl;
      // cycle through and display the board
      for (int i = 0; i < 8; i++)
      {
         cout << 9 - (i + 1) << " ";
         for (int j = 0; j < 8; j++)
            cout << board[i][j];
         cout << endl;
      }
   }
   else
   {
      cout << "\E[H\E[2J" 
           << "  ";

      for (char c = 'a'; c < 'i'; c++)
         cout << " " << c << " ";

      cout << endl;

      for (int i = 0; i < 8; i++)
      {
         cout << 9 - (i + 1) << " ";
         for (int j = 0; j < 8; j++)
         {
            // make sure that the uppers and lowers don't matter.
            blackSquare = (i + j) % 2;
            tempPiece = board[i][j];
            blackPiece = isupper(tempPiece);
            tempPiece = toupper(tempPiece);
            if (tempPiece == 'P')
               tempPiece = tolower(tempPiece);
            if (!blackSquare && !blackPiece)
               cout << WHITEWHITE << " " << tempPiece << " \E[0m";
            else if (!blackSquare && blackPiece)
               cout << WHITEBLACK << " " << tempPiece << " \E[0m";
            else if (blackSquare && !blackPiece)
               cout << BLACKWHITE << " " << tempPiece << " \E[0m";
            else if (blackSquare && blackPiece)
               cout << BLACKBLACK << " " << tempPiece << " \E[0m";
         }
         cout << endl; 
      }
   }
}

/**********************************************************************
* void read(moves, board, simple) - this will read in a board, check 
* to make sure it works properly, and then send it to be displayed if 
* it does. 
***********************************************************************/
void read(vector < string > &moves, char board[][8], bool simple)
{
   bool validBoard = true;
   string errorMessage;

   string fileName;
   cout << "Filename: ";
   cin.ignore();
   getline(cin, fileName);

   ifstream fin(fileName.c_str());

   // If the file fails to open, let the user know about it.
   if (fin.fail())
   {
      cout << "Unable to read file: " << fileName << endl;
      return;
   }

   // Add the moves from the file to be read into the board.
   string fileMove;
   while (fin >> fileMove)
   {
      moves.push_back(fileMove);
   }

   // iterate through the vector and parse the moves
   vector < string > ::iterator p;
   for (p = moves.begin(); p < moves.end(); p++)
   {
      Move tmpMove;
      tmpMove.castleK = false;
      tmpMove.castleQ = false;
      tmpMove.text = *p;
      if (!parse(tmpMove, board, errorMessage))
      {
         cout << "Error parsing file "
               << fileName
               << " with move \'"
               << errorMessage;
         validBoard = false;
      }
      else
      {
         // if they pass the tests, excecute them
         execute(tmpMove, board);
         display(board, simple);
      }
   }

   // if things are not good, remove everything that got put into the vector
   if (!validBoard)
   {
      vector < string > ::iterator p;
      for (p = moves.begin(); p < moves.end(); p++)
      {
         *p = "";
      }
      initialize(board);
   }

   // close the file
   fin.close();
}

/**********************************************************************
* INTERACT
*    This will contain all the interaction with the user during the 
*    game of chess.
***********************************************************************/
void interact(vector < string > &moves, char board[][8])
{
   // declare variables
   string errorMessage;
   string input;
   bool whiteTurn;
   bool simple = false;
   bool quit = false;

   // initiate loop
   do
   {
      // check who's turn it is
      switch (moves.size() % 2)
      {
         case 0:
            cout << "(White): ";
            break;
         case 1:
            cout << "(Black): ";
            break;
      }

      cin >> input;
      if (input == "?")
      {
         cout << "Options:\n"
               << " ?      Display these options\n"
               << " b2b4   Specify a move using the Smith Notation\n"
               << " read   Read a saved game from a file\n"
               << " test   Simple display for test purposes\n"
               << " quit   Leave the game. You will be prompted to save\n";
      }
      else if (input == "read")
         read(moves, board, simple);
      else if (input == "test")
      {
         simple = true;
         display(board, simple);
      }
      else if (input == "quit")
         quit = true;
      else
      {
         Move move;
         move.castleK = false;
         move.castleQ = false;
         move.text = input;

         if (parse(move, board, errorMessage))
         {
            execute(move, board);
            display(board, simple);
            moves.push_back(move.text);
         }
         else
         {
            cout << "Error in move \'"
                  << errorMessage
                  << "        Type ? for more options\n";
         }

      }
   } while (quit == false);

   // quit the game and write to a file if the user so chooses
   write(moves);
   return;
}

/**********************************************************************
* bool parse() makes sure that all of the input is valid and handles
* all of the error messages if the input is not valid.
***********************************************************************/
inline bool parse(Move &move, char board[][8], string &errorMessage)
{
   if (move.text[0] < 'a' || move.text[0] > 'h')
   {
      errorMessage = move.text + "\': Invalid format of source coordinates\n";
      return false;
   }
   if (move.text[1] <  '1'  || move.text[1] >  '8')
   {
      errorMessage = move.text + "\': Invalid format of source coordinates\n";
      return false;
   }
   if (move.text[2] < 'a' || move.text[2] > 'h')
   {
      errorMessage = move.text + 
         "\': Invalid format of destination coordinates\n";
      return false;
   }
   if (move.text[3] <  '1'  || move.text[3] >  '8')
   {   
      errorMessage = move.text +
          "\': Invalid format of destination coordinates\n";
      return false;
   }

   // If there is a 5th character input...
   if (move.text.length() == 5)
   {
      switch (move.text[4])
      {
         case 'p':
         case 'n':
         case 'b':
         case 'r':
         case 'q':
         case 'k':
            move.capture = true;
            break;
         case 'c':
            move.castleK = true;
            break;
         case 'C':
            move.castleQ = true;
            break;
         default:
            errorMessage = move.text 
               + "\': Unknown promotion piece specification\n";
            return false;
      }
   }

   move.source.c  = move.text[0] - 'a';
   move.source.R  = 8 - (move.text[1] - 48);
   move.dest.c = move.text[2] - 'a';
   move.dest.R = 8 - (move.text[3] - 48);

   /***********************************************
   * Make sure the proper information is passed.
   ***********************************************/
   assert(move.source.c > -1 && move.source.c < 9);
   assert(move.source.R > -1 && move.source.R < 9);
   assert(move.dest.c > -1 && move.dest.c < 9);
   assert(move.dest.R > -1 && move.dest.R < 9);

   if (board[move.source.R][move.source.c] == ' ')
   {
      errorMessage = move.text 
         + "\': No piece in the source coordinates position\n";
      return false;
   }
   return true;
}

/**********************************************************************
* execute(move, board) makes sure that the users input happens within
* the game. 
***********************************************************************/
void execute(Move &move, char board[][8])
{
   // castling
   if (move.castleK)
   {
      board[move.dest.R][7] = ' ';
      board[move.dest.R][6] = 'K';
      board[move.dest.R][5] = 'R';
      board[move.dest.R][4] = ' ';
   }
   else if (move.castleQ)
   {
      board[move.dest.R][0] = ' ';
      board[move.dest.R][1] = ' ';
      board[move.dest.R][2] = 'K';
      board[move.dest.R][3] = 'R';
      board[move.dest.R][4] = ' ';
   }

   else
   {
      board[move.dest.R][move.dest.c] = board[move.source.R][move.source.c];
      board[move.source.R][move.source.c] = ' ';
   }
}

/**********************************************************************
* write(moves) - Allows the user to save the game moves to a file ending
* in .txt
***********************************************************************/
void write(vector < string > &moves)
{
   string fileName;

   cout << "To save a game, please specify the filename.\n"
         << "    To quit without saving a file, just press <enter>\n";

   cin.ignore();
   getline(cin, fileName);

   if (fileName.empty())
      exit(0);

   ofstream fout(fileName.c_str());
   if (fout.fail())
   {
      cout << "Could not write to file " << fileName << endl;
      return;
   }

   vector < string > ::iterator p;
   for (p = moves.begin(); p < moves.end(); p++)
   {
      fout << *p << ' ';
   }

   fout.close();
   return;
}
