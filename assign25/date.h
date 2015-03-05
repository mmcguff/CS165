/***********************************************************************
* Program:
*    Assignment 25, Basic Date Class
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
      // Default Constructor
      Date();

      // Non-Default Constructor 3 Inputs
      Date(int year, int month, int day);

      // Non-Default Constructor 1 Input
      Date (int year);

      // Destructor
      ~Date();

      // Getters
      inline int getYear(){return year;};
      inline int getMonth(){return month;};
      inline int getDay(){return day;};

      // Setters
      bool setDate(int year, int month, int day);
      inline bool setYear(int year){this->year = year; return true;};
      inline bool setMonth(int month){this->month = month; return true;};
      inline bool setDay(int day){this->day = day; return true;};
      inline bool setShort(){isShort = true; return true;};
      inline bool setLong(){isShort = false; return true;};

      // Initialize and Un-initialize before constructors.
      void initialize();
      void uninitialize();

      // Display
      void display();
   private:
      int day, month, year;
      static bool isShort;
      void assertDate();
      void displayShort();
      void displayLong();
      int daysMonth(int month, int year);
      bool isLeapYear(int year);
   protected:
};

#endif // DATE_H
