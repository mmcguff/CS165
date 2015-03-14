#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include "move.h"
#include <cassert>
#include <cstdlib>

class Board
{
  public:

    // Default constructor to call other constructors...
    Board() : test(false), allocated(false) {resetBoard();};

    // Get the piece to put it on the board.
    Piece & getPiece();

    void swap(Move & move);
    void resetBoard();
    void freeBoard();

    // Getters
    bool getTest() const { return test;};

    // Setters
    bool setTest() { test = (!test); return test;};

    // Operators!!!
    Piece & operator [] (const Position & pos)
    {return *square[pos.getCol()][pos.getRow()];};

    friend ostream & operator << (ostream & out, const Board & rhs);

  private:

    bool test;
    bool allocated;
    Piece * square[8][8];
};

#endif //BOARD_H
