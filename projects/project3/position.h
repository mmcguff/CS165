/****************************************************************
 * POSITION points to a specific location on the board
 ***************************************************************/
#ifndef POSITION_H 
#define POSITION_H

#include <iostream>
#include <cassert>
#include <sstream>
using namespace std;

class Position
{
  public:
    Position() {};
    Position(int row, int col) : row(row), col(col) {};

    void setRow(int nRow) {row = nRow;    };
    void setCol(int nCol) {col = nCol;    };

    int getCol()  const  {return col;    };
    int getRow()  const  {return row + 1;};

    bool isValid() const;

    Position & operator = (const char *s);
    bool operator == (const Position & rhs) const;
    friend istream & operator >> (istream & in,        Position & pos);
    friend ostream & operator << (ostream & out, const Position & pos);

  private:
    int row;
    int col;
};

#endif //POSITION_H
