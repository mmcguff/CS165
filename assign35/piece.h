#ifndef ASSIGN35_H
#define ASSIGN35_H

#include <iostream>    // You need to be able to use cout, cin, etc...
#include <iomanip>     // In case you need to manipulate stuff...
#include <cstdlib>     // Get all of the standard C library.
#include <string>      // For strings. You will need it later...
#include <vector>      // Vectors. Because they rock...
using namespace std;   // We are not using any custom STL's

class Piece
{
  public:
    Piece(bool isWhite);                 // Default constructor for children.

    virtual char getLetter() const = 0;  // This will never be called by Piece.
    virtual int getScore() const = 0;    // This will never be called by Piece.
    bool getIsWhite() const;             // Needed for this assignment?
  protected:
    bool isWhite;                        // Accessible by all children classes.
};

class King : public Piece
{
  public:
    King(bool isWhite);                  // See piece.cpp for further details.
    virtual char getLetter() const;      // Returns 'k' or 'K'
    virtual int getScore() const {};     // Not really used for this program...
};

class Queen : public Piece
{
  public:
    Queen(bool isWhite);                 // See piece.cpp for further details.
    virtual char getLetter() const;      // Returns 'q' or 'Q'
    virtual int getScore() const {};     // Not really used for this program...
};

class Rook : public Piece
{
  public:
    Rook(bool isWhite);                  // See piece.cpp for further details.
    virtual char getLetter() const;      // Returns 'r' or 'R'
    virtual int getScore() const {};     // Not really used for this program...
};

class Knight : public Piece
{
  public:
    Knight(bool isWhite);                // See piece.cpp for further details.
    virtual char getLetter() const;      // Returns 'n' or 'N'
    virtual int getScore() const {};     // Not really used for this program...
};

class Bishop : public Piece
{
  public:
    Bishop(bool isWhite);                // See piece.cpp for further details.
    virtual char getLetter() const;      // Returns 'b' or 'B'
    virtual int getScore() const {};     // Not really used for this program...
};

class Pawn : public Piece
{
  public:
    Pawn(bool isWhite);                  // See piece.cpp for further details.
    virtual char getLetter() const;      // Returns 'p' or 'P'
    virtual int getScore() const {};     // Not really used for this program...
};

class Space : public Piece
{
  public:
    Space();                             // See piece.cpp for further details.
    virtual char getLetter() const;      // Returns ' ' (A space).
    virtual int getScore() const{};      // Not really used for this program...
};

#endif
