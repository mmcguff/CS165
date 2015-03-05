#include <iostream>
#include "bullet.h"
#include "rifle.h"
#include "vector.h"
#include "point.h"
#include "bird.h"
using namespace std;

class Skeet
{
   public:
      // Constructors and Destructors
      Skeet ();
      ~Skeet();
   
      // Functions
      void draw();
      void interact();
      void advance();

   private:
      
      // Private Variables.
      int rifle;
      int bird;
      int bullets;
      bool hit;
      bool miss;
}
