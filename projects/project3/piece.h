#ifndef PIECE_H
#define PIECE_H

#include "position.h"
#include <vector>
#include <iostream>
using namespace std;

#define WHITE_WHITE "\E[31;47m"
#define WHITE_BLACK "\E[30;47m"
#define BLACK_WHITE "\E[37;41m"
#define BLACK_BLACK "\E[30;41m"
#define RETURN      "\E[0m"

class Piece
{
  public:
   Piece() {};
  Piece(bool white, int row, int col, char letter) :
   pos(row, col), letter(letter), fWhite(white) {};

   void display() const
   {
      if (!fWhite)
         cout << (char)toupper(getLetter());
      else
         cout << (char)tolower(getLetter());
   };

   char getLetter() const { return letter;       };
   virtual void getScore() = 0;
   virtual void getMoves() = 0;
   bool getColor()  const {return isWhiteSquare;};
   bool isWhite()   const {return fWhite;};


   void setSquareColor(int row, int col)
   {
      isWhiteSquare = ((row + col) % 2 ? false : true);
    }

   friend ostream & operator << (ostream & out, const Piece & rhs);

  protected:
   Position pos;
   bool isWhiteSquare;
   char letter;
   bool fWhite;
};

class Pawn : public Piece
{
  public:
  Pawn(bool white, int row, int col) :
   Piece(white, row, col, 'p') {};
   void getMoves() {};
   void getScore() {};
  private:
   bool fMoved;
};

class Rook : public Piece
{
  public:
  Rook(bool white, int row, int col) :
   Piece(white, row, col, 'R') {};
   void getMoves() {};
   void getScore() {};
  private:
   bool fMoved;
};

class Knight : public Piece
{
  public:
   Knight(bool white, int row, int col) :
   Piece(white, row, col, 'N') {};
   void getMoves() {};
   void getScore() {};
};

class Bishop : public Piece
{
  public:
  Bishop(bool white, int row, int col) :
   Piece(white, row, col, 'B') {};
   void getMoves() {};
   void getScore() {};
};

class Queen : public Piece
{
  public:
  Queen(bool white, int row, int col) :
   Piece(white, row, col, 'Q') {};
   char getLetter() const { return letter;       };
   void getMoves() {};
   void getScore() {};
};

class King : public Piece
{
  public:
  King(bool white, int row, int col) :
   Piece(white, row, col, 'K') {};
   void getMoves()             {};
   void getScore()             {};
  private:
   bool fMoved;
};

class Space : public Piece
{
  public:
   Space() {};
   Space(bool white, int row, int col) :
   Piece(white, row, col, ' ') {};
   void getMoves()        {};
   void getScore()        {};
};

#endif //PIECE_H
