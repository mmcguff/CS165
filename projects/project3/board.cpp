#include "board.h"

/*****************************************************************************
 * CLASS: Board
 *****************************************************************************
 * FUNCTION: void freeBoard()
 *****************************************************************************
 * INPUT: None
 *****************************************************************************
 * PROCESS: Loop through the 8x8 array and remove all of the pieces.
 *****************************************************************************
 * OUTPUT: None
 *****************************************************************************/
void Board::freeBoard()
{
   if (allocated == true)
   {
      for (int i = 0; i < 8; i++)
      {
         for (int p = 0; p < 8; p++)
         {
            delete square[i][p];
         }
      }
   }
}

/*****************************************************************************
 * CLASS: Board
 *****************************************************************************
 * FUNCTION: void resetBoard()
 *****************************************************************************
 * INPUT: None
 *****************************************************************************
 * PROCESS: Redraw the chess board, filling the proper spaces with pieces.
 *****************************************************************************
 * OUTPUT: None
 *****************************************************************************/
void Board::resetBoard()
{
   // Spaces for all middle rows
   for (int i = 2; i < 6; i++)
   {
      for (int p = 0; p < 8; p++)
         square[i][p] = new Space(false, i, p); // create a new pawn
   }

   // A pawn for each column
   for (int i = 0; i < 8; i++)
   {
      square[6][i] = new Pawn(false, 1, i);   // white pawns
      square[1][i] = new Pawn(true, 6, i);    // black pawns
   }

   // Draw the major white pieces.
   square[7][0] = new Rook  (false, 0, 0);    // white rook
   square[7][1] = new Knight(false, 0, 1);    // white knight
   square[7][2] = new Bishop(false, 0, 2);    // white bishop
   square[7][3] = new King  (false, 0, 3);    // white king
   square[7][4] = new Queen (false, 0, 4);    // white queen
   square[7][5] = new Bishop(false, 0, 5);    // white bishop
   square[7][6] = new Knight(false, 0, 6);    // white knight
   square[7][7] = new Rook  (false, 0, 7);    // white rook

   // Draw the major black pieces.
   square[0][0] = new Rook  (true, 7, 0);     // black rook
   square[0][1] = new Knight(true, 7, 1);     // black knight
   square[0][2] = new Bishop(true, 7, 2);     // black bishop
   square[0][3] = new King  (true, 7, 3);     // black king
   square[0][4] = new Queen (true, 7, 4);     // black queen
   square[0][5] = new Bishop(true, 7, 5);     // black bishop
   square[0][6] = new Knight(true, 7, 6);     // black knight
   square[0][7] = new Rook  (true, 7, 7);     // black rook

   allocated = true;
}

ostream & operator << (ostream & out, const Board & rhs)
{
   // Get rid of the previous chess board.
   system("clear");

   // If they want the test display.
   if (rhs.test == true)
   {
      out << "  abcdefgh\n";          // Display the top part of the board.
      for (int i = 7; i >= 0; i--)
      {
         out << i+1 << ' ';           // Put the left hand number coordinates.
         for ( int p = 0; p < 8; p++)
         {
            rhs.square[i][p]->display(); // Display the pre-generated board.
         }
         out << endl;                 // Drop to the next line of the board.
      }
   }

   // real display
   else if (rhs.test == false)
   {
      // Display the top part of the board.
      out << "   a  b  c  d  e  f  g  h \n";

      for (int row = 7; row >= 0; row--)
      {
         out << row + 1 << ' ';       // Put the left hand number coordinates.

         for ( int col = 0; col < 8; col++)
         {
            // gets the color of the square behind the piece...
            rhs.square[row][col]->setSquareColor(row, col);

            // and output it
            out << * rhs.square[row][col];
         }
         out << ' ' << row+1 << endl;
      }

      // Display the bottom part of the board.
      out << "   a  b  c  d  e  f  g  h \n";
   }
   return out;
}

void Board::swap(Move & move)
{
   // new piece created to preform the swap
   Piece *tempPiece = square[move.getDes().getRow()]
      [move.getDes().getCol()];

   // Handle the capture.
   if (tempPiece->getLetter() != ' ')
   {
      // Remove the existing piece.
      square[move.getDes().getRow()][move.getDes().getCol()] =
         square[move.getSrc().getRow()][move.getSrc().getCol()];

      // Generate a new piece in the place of the old one.
      square[move.getSrc().getRow()][move.getSrc().getCol()]
         = new Space(false,move.getSrc().getRow(),move.getSrc().getCol() );
   }
   else
   {
   square[move.getDes().getRow()][move.getDes().getCol()] =
      square[move.getSrc().getRow()][move.getSrc().getCol()];

   square[move.getSrc().getRow()][move.getSrc().getCol()] = tempPiece;
   }
}
