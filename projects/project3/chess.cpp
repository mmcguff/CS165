#include "chess.h"

void Chess::read()
{
   board.resetBoard();
   numMoves = 0;

   cout << "FileName: ";
   getFileName();

   board.resetBoard();

   if (readFile())
   {
      if (parse()); 
      else
         cout << "Error parsing file " << fileName << endl;
   }
   else
      cout << "Error reading file " << fileName << endl;
}

bool Chess::readFile()
{
   ifstream fin(fileName.c_str());
   
   if (fin.fail())
   {
      cout << "Error reading file: \'"
           << fileName
           << "\'\n";

      return false;
   }

   while (fin >> move)
   {
      moves.push_back (move);
      numMoves++;
   }
   fin.close();

   return true;
}

bool Chess::parse()
{
   for (int i = 0; i < numMoves; i++)
   {
      Position source = moves[i].getSrc();
      Position dest   = moves[i].getDes();

      if (!source.isValid())
      {
         cout << "Error parsing file " << fileName
              << " with move \'"        << moves[i]
              << "\': Invalid format of source coordinates\n";
         numMoves = 0;
         return false;
      }
      else if (!dest.isValid())
      {
         cout << "Error parsing file "  << fileName
              << " with move \'"        << moves[i]
              << "\': Invalid format of destination coordinates\n";
         numMoves = 0;
         return false;
      }
      else
      {
         try
         {
            board.swap(moves[i]);
         }
         catch (char key)
         {
            cout << "Error parsing file "  << fileName
                 << " with move \'"        << moves[i];
            switch (key)
            {
               case 's':
                  cout << "\': No piece in the source "
                       << "coordinates position\n";
                  numMoves = 0;
                  break;
               case 'e':
                  cout << "\': Unknown promotion piece specification\n";
                  numMoves = 0;
                  break;
            }
            return false;
         }
      }
   }
   return true;
}

void Chess::write()
{
   cout << "To save a game, please specify the filename.\n"
        << "    To quit without saving a file, just press <enter>\n";
   getFileName();
   if (fileName != " ")
   {
      if (writeFile());
      else
         cout << "Error saving file\n";
   }


}

bool Chess::writeFile()
{
   ofstream fout(fileName.c_str());

   if (fout.fail())
      return false;

   for (int i = 0; i < numMoves; i++)
   {
      fout << moves[i]     << ' ';
      fout << moves[i + 1] << endl;
      i++;
   }

   fout.close();
   return true;
}

void Chess::displayOptions()
{
   cout << "Options: \n"
        << "?       Display these options\n"
        << "b2b4    Specify a move using the Smith notation\n"
        << "read    Read a saves game from a file\n"
        << "help    Display all possible moves for a given piece\n"
        << "test    Simple display for test purposes\n"
        << "rank    Who is winning? What is the rank\n"
        << "quit    Leave the game. You will be prompted to save\n"
        << "smith   Briefly explains the Smith Notation\n"; // Extra Credit?
}

void Chess::displaySmith()
{
   cout << "Smith notation works by specifying the beginning and the ending\n"
        << "coordinates for any given piece (ex. 'b2b4' moves a pawn).\n"
        << "For convienience, the coordinates have been labeled on the\n"
        << "margins of the board.\n\n"
        << "Sometimes you may want to execute a special move such as\n"
        << "castling. In Smith notation, it is declared by adding a letter\n"
        << "to the end of the coordinates (such as 'e1b1c').\n"
        << "here is a list of the special moves and their corresponding\n"
        << "letters for smith notation:\n"
        << "Castling:       c\n"
        << "En-passant:     e\n"
        << "Pawn promotion: p\n"
        << "Capturing takes the letter of the target piece\n\n";
}

void Chess::interact(Move & move)
{
   string option;
   cin >> option;

   char m;

   if (option == "?")
      m = '?';
   if (option == "read")
      m = 'r';
   if (option == "help")
      m = 'h';
   if (option == "test")
      m = 't';
   if (option == "rank")
      m = 'R';
   if (option == "quit")
      m = 'q';
   if (option == "smith")
      m = 's';
   else
      move = option;

   switch (m)
   {
      case '?':
         displayOptions();
         break;
         
      case 'r':
         read();
         cout << board;
         break;
         
      case 'q':
         {
         write();
         fQuit = true;
         bool theChurch = true;
         break;
         }

      case 'h':
         // Still working on this piece.
         cout << "This option still in development\n";
         break;

      case 't':
         board.setTest();
         cout << *this;
         break;

      case 'R':
         // Still working on this option.
         cout << "This option still in development\n";
         break;

      case 's':
         displaySmith();
         break;
         
      default:
         numMoves++;

         moves.push_back(move);
         board.swap(move);
         cout << *this; 
   }
}

Chess & Chess::operator ++(int postfix)
{
   cout << (getNumMoves() % 2 ? "Black: " : "White: ");
   
   interact(move);

   return *this;
}

ostream & operator << (ostream & out, const Chess & rhs)
{
   out << rhs.board;
   return out;
};

int main()
{
   Chess chess;
   
   cout << chess;       // Put the board on the table for the user to see it.

   while(!chess.quit()) // Continue playing until the user specifies they quit.
   {
      chess++;
   }
   
   return 0;
}
