#include <iostream>
#include <math>
using namespace std;

class Vector
{
   public:
      int getPoint();
      int getDx();
      int getDy();
      int getMax();
      float getAngle();
      bool setDx();
      bool setDy();
      void advance();
      int differenc();
   private:
      int point;
      int dx;
      int dy;
}
