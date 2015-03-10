#ifndef ASSIGN32_H
#define  ASSIGN32_H

#include <iostream>
using namespace std;
class Piece
{
  public:
 
    // Constructors and Destructors
    Piece (bool isWhite);
    ~Piece();
    
    // Getters
    bool getIsWhite() const;
    bool getLetter() const;
 
  private:
 
    // Private variables.
    bool isWhite;
};

#endif
