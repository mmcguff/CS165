/***********************************************************************
* Program:
*    Assignment 13, Position           
*    Brother Sloan, CS165
* Author:
*    Larry Dewey
* Summary: 
*    This program is designed to open a file, and to try reading a line
*	 from the file. If there are errors, it will output them. 
*
*    Estimated:  ? hrs   
*    Actual:     1.0 hrs
************************************************************************/
#include <iostream>
using namespace std;

/***********************************************************************
 * Creates a container for the position to be stored in. 
 ***********************************************************************/
struct Position
{
   int row;
   int col;
};

/***********************************************************************
 * Prompts the user to enter the x and y coordinates.
 ***********************************************************************/
void prompt(Position &pos)
{
   cout << "X coordinate: ";
   cin >> pos.row;
   cout << "Y coordinate: ";
   cin >> pos.col;
}

/***********************************************************************
 * Output the positions in the coordinate format of (X, Y).
 ***********************************************************************/
void display(const Position &pos)
{
   cout << "(" << pos.row << ", " << pos.col << ")" << endl;
}

/***********************************************************************
 * Main is the powerhouse of the program. it initializes the structure, 
 * and the calls the two other functions
 ***********************************************************************/
int main()
{
   Position pos;

   // get the data
   prompt(pos);

   // display the data
   display(pos);

   return 0;
}

