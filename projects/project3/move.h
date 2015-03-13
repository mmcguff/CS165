#ifndef _MOVE_
#define _MOVE_

#include <string>
#include "position.h"
#include <cassert>
#include <iostream>
#include <sstream>

#define PIECE_EMPTY ' '

class Move
{
  public:
      Move();
      Move(const Move & rhs)           { *this = rhs;      };
      const Position & getDes()  const { return dest;      };
      const Position & getSrc()  const { return source;    };
      string getText() const;
      char getPromotion()        const { return piece;     };
      char getCapture()          const { return capture;   };
      bool getEnPassant()        const { return enpassant; };
      bool getCastleK()          const { return castleK;   };
      bool getCastleQ()          const { return castleQ;   };
      bool getWhiteMove()        const { return isWhite;   };
      bool operator == (const string & rhs) const { return getText() == rhs; };
      bool operator != (const string & rhs) const { return getText() != rhs; };
      bool operator == (const Move & rhs)   const;
      bool operator != (const Move & rhs)   const { return !(*this == rhs); } ;

      void setCapture(char letter)      { capture    = tolower(letter); };
      void setWhiteMove(bool f)         { isWhite    = f;               };
      void setSrc(const Position & src) { source     = src;             };
      void setDes(const Position & des) { dest       = des;             };
      void setEnPassant()               { enpassant  = true;            };
      void setPromote(char letter)      { piece      = letter;          };
      void setCastle(bool isKing)
      {
         if (isKing)
            castleK = true;
         else
            castleQ = true;
      };

      friend ostream & operator << (ostream & out, Move & rhs);
      friend istream & operator >> (istream & in,  Move & rhs) throw (string);

      const Move & operator = (const Move & rhs);
      const Move & operator = (const string & s) throw ( string )
         {
            read(s);
            return *this;
         }
      const Move & operator = (const char *s) throw ( string )
         {
            read(string(s));
            return *this;
         }

  private:
      void read(const string & s) throw(string);

      Position source;
      Position dest;
      char piece;
      char capture;
      bool enpassant;
      bool castleK;
      bool castleQ;
      bool isWhite;
      string error;
};

#endif // _MOVE_
