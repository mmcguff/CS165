/***********************************************************************
* Program:
*    Assignment 28, The Gauntlet III
*    Brother Sloan, CS165
* Author:
*    Larry Dewey
* Summary:
*    This is a driver program for a simple date class.  Your job is
*    to write date.h and date.cpp.  This file is to remain untouched.
************************************************************************/

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

class Date
{
   public: // Available to everyone!
   
      // Constructors & Destructors
      Date();
      Date(const int year);
      Date(const int year, const int month, const int day);
      Date(const int year, const int month, const int day, const int postfix);
      ~Date();
      
      // Operators
      // Insertion and Extraction Operators
      friend ostream & operator << (ostream & out, const Date & rhs);
      friend istream & operator >> (istream & out, Date & rhs);

      // Arithmetic Operators
      Date operator + (const Date & rhs);
      Date operator + (const int number);
      Date operator - (const Date & rhs);
      Date operator - (const int number);
      Date operator * (const Date & rhs);
      Date operator * (const int number);
      Date operator / (const Date & rhs);
      Date operator / (const int number);

      // Add-onto Operators
      Date & operator += (const Date & rhs);
      Date & operator += (const int number);
      Date & operator -= (const Date & rhs);
      Date & operator -= (const int number);
      Date & operator *= (const Date & rhs);
      Date & operator *= (const int number);
      Date & operator /= (const Date & rhs);
      Date & operator /= (const int number);
      
      // Assignment Operator
      Date & operator = (const Date & rhs);

      // Increment and Decrement Operators
      Date & operator ++ ();
      Date & operator -- ();
      Date operator ++ (int postfix);
      Date operator -- (int postfix);

      // Negative and Not Operators
      Date operator - ();
      bool operator ! ();

      // Comparison Operators
      bool operator == (const Date & rhs);
      bool operator != (const Date & rhs);
      bool operator > (const Date & rhs);
      bool operator >= (const Date & rhs);
      bool operator < (const Date & rhs);
      bool operator <= (const Date & rhs);
      
      // Getters
      inline int getYear() const {return year;};
      inline int getMonth() const {return month;};
      inline int getDay() const {return day;};
      
      // Setters
      inline bool setYear(int year) {return (this->year = year);};
      inline bool setMonth(int month) {return (this->month = month);};
      inline bool setDay(int day) {return (this->day = day);};
      inline bool setShort(){return (isShort = true);};
      
      inline bool setDate(int year, int month, int day){
                     this->year = year;
                     this->month = month;
                     this->day = day;
                     return true;
                     };
                     
      void display() const;
      void displayDays() const;
      void displayShort() const;
      void displayLong() const;
      int getDaysLeft() const;
      void validateDate();
      int postfix;
      
   private: // Available to members and friends only!
      
      void assertDate() const;
      static bool isShort;
      int day, month, year;
      int daysMonth(const int month, const int year) const;
      bool isLeapYear(const int year) const;
};

inline Date operator + (const int number, Date & rhs)
{
   return Date(rhs.getYear(), rhs.getMonth(), number + rhs.getDay());
}


#endif
