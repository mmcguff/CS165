#include "piece.h"
char Piece :: getLetter() const
{
  return (' ');
}

char King::getLetter() const
{
  return (isWhite) ? 'k' : 'K';
}

char Queen::getLetter() const
{
  return (isWhite) ? 'q' : 'Q';
}

char Rook::getLetter() const
{
  return (isWhite) ? 'r' : 'R';
}

char Knight::getLetter() const
{
  return (isWhite) ? 'n' : 'N';
}

char Bishop::getLetter() const
{
  return (isWhite) ? 'b' : 'B';
}

char Pawn::getLetter() const
{
  return (isWhite) ? 'p' : 'P';
}
