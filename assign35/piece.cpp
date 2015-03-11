#include "piece.h"
char Space::getLetter()
{
  return (' ');
}

char King::getLetter()
{
  return (isWhite) ? 'k' : 'K';
}

char Queen::getLetter()
{
  return (isWhite) ? 'q' : 'Q';
}

char Rook::getLetter()
{
  return (isWhite) ? 'r' : 'R';
}

char Knight::getLetter()
{
  return (isWhite) ? 'n' : 'N';
}

char Bishop::getLetter()
{
  return (isWhite) ? 'b' : 'B';
}

char Pawn::getLetter()
{
  return (isWhite) ? 'p' : 'P';
}
