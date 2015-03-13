#include"piece.h"

ostream & operator << (ostream & out, const Piece & rhs)
{
   if (rhs.isWhite() && rhs.getColor())
      out << WHITE_WHITE                    << ' '
          << rhs.getLetter() << ' ';
   else if (rhs.isWhite() && !rhs.getColor())
      out << BLACK_WHITE     << ' '
          << rhs.getLetter() << ' ';
   else if (!rhs.isWhite() && rhs.getColor())
      out << WHITE_BLACK     << ' '
          << rhs.getLetter() << ' ';
   else if (!rhs.isWhite() && !rhs.getColor())
      out << BLACK_BLACK     << ' '
          << rhs.getLetter() << ' ';
   out << RETURN;
   return out;
}
