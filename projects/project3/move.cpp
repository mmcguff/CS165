#include "move.h"

Move::Move() : piece(PIECE_EMPTY), capture(PIECE_EMPTY), enpassant(false),
               castleK(false), castleQ(false), isWhite(true)
{
  // Do nothing =)
}

bool Move::operator == (const Move & rhs) const
{
   if (source    == rhs.getSrc()       &&
       dest      == rhs.getDes()       &&
       piece     == rhs.getPromotion() &&
       castleK   == rhs.getCastleK()   &&
       castleQ   == rhs.getCastleQ()   &&
       enpassant == rhs.getEnPassant() &&
       capture   == rhs.getCapture()   &&
       piece     == rhs.getPromotion())
   {
      assert(enpassant == rhs.getEnPassant());
      assert(castleK == rhs.getCastleK());
      assert(castleQ == rhs.getCastleQ());
      assert(piece == rhs.getPromotion());
      return true;
   }
   else
      return false;
}

string Move::getText() const
{
   if (error.length())
      return error;

   std::ostringstream sout;
   sout << source << dest;

   if (enpassant)
      sout << "E";
   if (castleK)
      sout << "c";
   if (castleQ)
      sout << "C";
   if (piece != PIECE_EMPTY)
      sout << piece;
   if (capture != PIECE_EMPTY)
      sout << (char)tolower(capture);

   return sout.str();
}

const Move & Move::operator = (const Move & rhs)
{
   source = rhs.getSrc();
   dest = rhs.getDes();
   piece = rhs.getPromotion();
   capture = rhs.getCapture();
   enpassant = rhs.getEnPassant();
   castleK = rhs.getCastleK();
   castleQ = rhs.getCastleQ();
   isWhite = rhs.getWhiteMove();
   error = rhs.error;
   return *this;
}

void Move::read(const string & s) throw(string)
{
   *this = Move();

   try
   {
      source = s.c_str() + 0;
   }
   catch (string sError)
   {
      error = s;
      throw string("Invalid specification of source coordinates");
   }

   try
   {
      dest = s.c_str() + 2;
   }
   catch (string sError)
   {
      error = s;
      throw string("Invalid specification of destination coordinates");
   }

   for (unsigned int i = 4; i < s.size(); i++)
   {
      switch(s[i])
      {
         case 'p':   // capture a pawn
         case 'n':   // capture a knight
         case 'b':   // capture a bishop
         case 'r':   // capture a rook
         case 'q':   // capture a queen
         case 'k':   // !! you can't capture a king you silly!
            capture = tolower(s[i]);
            break;

         case 'c':  // short castling or kings castle
            castleK = true;
            break;
         case 'C':  // long castling or queen castle
            castleQ = true;
            break;
         case 'E':  // En-passant
            enpassant = true;
            break;

         case 'N':  // Promote to knight
         case 'B':  // Promote to Bishop
         case 'R':  // Promote to Rook
         case 'Q':  // Promote to Queen
            piece = s[i];
            break;

         default:
            error = s;
            throw string("Unknown promotion piece specification");
            break;
      }
   }

   return;
}

ostream & operator << (ostream & out, Move & rhs)
{
   out << rhs.getText();

   return out;
}

istream & operator >> (istream & in,  Move & rhs) throw (string)
{   
   string s;
   if (in >> s)
      rhs = s;

   return in;   
}

