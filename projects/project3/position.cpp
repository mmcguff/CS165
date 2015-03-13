#include "position.h"

bool Position::isValid() const
{
   if (row > 7 || row < 0 || col > 7 || row < 0)
      return false;
   else
      return true;
}

istream & operator >> (istream & in, Position & pos)
{

   int tempRow;
   char tempCol;
   cout << "called extraction opperator!\n";
   in >> tempCol >> tempRow;
   cout << tempRow << tempCol << endl;;

   pos.row = tempRow;
   pos.col = (int)tempCol;

   return in;
}

ostream & operator << (ostream & out, const Position & pos)
{
   out  << (char)(pos.getCol() + 'a') << pos.getRow() + 1;
   return out;
}

Position & Position::operator = (const char *s)
{
   col = (*s - 'a');
   row = (*(s+1) - '2');

   return *this;
}

bool Position::operator == (const Position & rhs) const
{
   if (col == rhs.col && row == rhs.row)
      return true;
   else
      return false;
}

