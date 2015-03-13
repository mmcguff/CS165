#ifndef CHESS_H
#define CHESS_H

#include <vector>
#include <string>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "board.h"
#include "move.h"
#include "piece.h"
using namespace std;

class Chess
{
  public:
  Chess() : numMoves(0), fQuit(false) {};

   void interact(Move & move);
   void displayOptions();
   void displaySmith();

   void getFileName() { cin >> fileName; };
   int getNumMoves() const { return numMoves; };

   void read();
   bool readFile();
   bool parse();
   void write();
   bool writeFile();
   bool quit()        { return fQuit;    };

   Chess & operator ++ (int postfix);
   friend ostream & operator << (ostream & out, const Chess & rhs);

  private:
   Board board;
   Move move;
   vector <Move> moves;
   int numMoves;
   string fileName;

   bool fQuit;
};

#endif //CHESS_H
