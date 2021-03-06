#ifndef ASSIGN34_H
#define ASSIGN34_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Piece
{
  public:
    Piece(bool isWhite) : isWhite(isWhite){};
    virtual char getLetter() const;
    virtual int getScore() const {};
    bool getIsWhite();
  protected:
    bool isWhite;
};

class King : public Piece
{
  public:
    King(bool isWhite) : Piece(isWhite) {};
    virtual char getLetter() const;
    //virtual int getScore();
};

class Queen : public Piece
{
  public:
    Queen(bool isWhite) : Piece(isWhite){};
    virtual char getLetter() const;
   // int getScore();
};

class Rook : public Piece
{
  public:
    Rook(bool isWhite) : Piece(isWhite){};
    virtual char getLetter() const;
    //int getScore();
};

class Knight : public Piece
{
  public:
    Knight(bool isWhite) : Piece(isWhite){};
    virtual char getLetter() const;
    //int getScore();
};

class Bishop : public Piece
{
  public:
    Bishop(bool isWhite) : Piece(isWhite){};
    virtual char getLetter() const;
    //int getScore();
};

class Pawn : public Piece
{
  public:
    Pawn(bool isWhite) : Piece(isWhite){};
    virtual char getLetter() const;
    //int getScore();
};

#endif
