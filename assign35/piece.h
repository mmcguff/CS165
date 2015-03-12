#ifndef ASSIGN35_H
#define ASSIGN35_H

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
    virtual char getLetter() const = 0;
    virtual int getScore() const = 0;
    bool getIsWhite() const;
  protected:
    bool isWhite;
};

class King : public Piece
{
  public:
    King(bool isWhite) : Piece(isWhite) {};
    virtual char getLetter() const;
    virtual int getScore() const {};
};

class Queen : public Piece
{
  public:
    Queen(bool isWhite) : Piece(isWhite){};
    virtual char getLetter() const;
    virtual int getScore() const {};
};

class Rook : public Piece
{
  public:
    Rook(bool isWhite) : Piece(isWhite){};
    virtual char getLetter() const;
    virtual int getScore() const {};
};

class Knight : public Piece
{
  public:
    Knight(bool isWhite) : Piece(isWhite){};
    virtual char getLetter() const;
    virtual int getScore() const {};
};

class Bishop : public Piece
{
  public:
    Bishop(bool isWhite) : Piece(isWhite){};
    virtual char getLetter() const;
    virtual int getScore() const {};
};

class Pawn : public Piece
{
  public:
    Pawn(bool isWhite) : Piece(isWhite){};
    virtual char getLetter() const;
    virtual int getScore() const {};
};

class Space : public Piece
{
  public:
    Space() : Piece(false){};
    virtual char getLetter() const;
    virtual int getScore() const{};
};

#endif
