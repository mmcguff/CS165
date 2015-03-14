#include "piece.h"

Piece :: Piece(bool isWhite) : isWhite(isWhite)
{
  // Assign the variables.
}

King :: King(bool isWhite) : Piece(isWhite)
{
  // When you call a King, make sure you make a piece.
}

Queen :: Queen(bool isWhite) : Piece(isWhite)
{
  // When you call a Queen, make sure you make a piece.
}

Rook :: Rook(bool isWhite) : Piece(isWhite)
{
  // When you call a Rook, make sure you make a piece.
}

Knight :: Knight(bool isWhite) : Piece(isWhite)
{
  // When you call a Knight, make sure you make a piece.
}

Bishop :: Bishop(bool isWhite) : Piece(isWhite)
{
  // When you call a Bishop, make sure you make a piece.
}

Pawn :: Pawn(bool isWhite) : Piece(isWhite)
{
  // When you call a Pawn, make sure you make a piece.
}

Space :: Space() : Piece(false)
{
  // When you call a Space, make sure you make a piece.
}

char King::getLetter() const
{
  // If piece is white, return piece white, else black.
  return (isWhite) ? 'k' : 'K';
}

char Queen::getLetter() const
{
  // If piece is white, return piece white, else black.
  return (isWhite) ? 'q' : 'Q';
}

char Rook::getLetter() const
{
  // If piece is white, return piece white, else black.
  return (isWhite) ? 'r' : 'R';
}

char Knight::getLetter() const
{
  // If piece is white, return piece white, else black.
  return (isWhite) ? 'n' : 'N';
}

char Bishop::getLetter() const
{
  // If piece is white, return piece white, else black.
  return (isWhite) ? 'b' : 'B';
}

char Pawn::getLetter() const
{
  // If piece is white, return piece white, else black.
  return (isWhite) ? 'p' : 'P';
}

char Space::getLetter() const
{
  // Doesn't matter, return a space.
  return (' ');
}
