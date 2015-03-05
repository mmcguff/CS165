/***********************************************************************
* Program:
*    Assignment 22, Basic Date Class
*    Brother Sloan, CS165
* Author:
*    Larry Dewey
* Summary:
*    This is a driver program for a simple date class.  Your job is
*    to write date.h and date.cpp.  This file is to remain untouched.
************************************************************************/

#ifndef DATE_H
#define DATE_H

#include <iostream>   // for COUT, CIN, CERR
#include <cassert>    // for ASSERT
#include <cstdlib>    // for EXIT
#include <string>     // for strings
#include <error.h>    // for cerr
using namespace std;

class Date
{
   public:
      void initialize();
      void uninitialize();
      bool setDate(int year, int month, int day);
      void displayLong();
   private:
      int * data;
      void assertDate();
      int daysMonth(int month, int year);
      bool isLeapYear(int year);
   protected:
};

#endif // DATE_H
