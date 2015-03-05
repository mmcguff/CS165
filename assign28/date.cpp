#include "date.h"

/******************************************************************************
 * Constructors for objects of Date.
 ******************************************************************************/

// No inputs expected.
Date::Date() : day(1), month(1), year(2000), postfix(0)
{
   validateDate();   // Make sure all of the values are adjusted properly.
   assertDate();     // Safety net to assure no wrong values are set.
}

// One input expected.
Date::Date(const int year) : day(1), month(1), year(2000), postfix(0)
{
   validateDate();   // Make sure all of the values are adjusted properly.
   assertDate();     // Safety net to assure no wrong values are sent.
}

// Three inputs expected.
Date::Date(const int year, const int month, const int day)
      : day(day), month(month), year(year), postfix(0)
{
   validateDate();   // Make sure all of the values are adjusted properly.
   assertDate();     // Safety net to assure no wrong values are sent.
}

// Special 4 input expected to output only the days.
Date::Date(const int year, const int month, const int day, const int postfix)
      : day(day), month(month), year(year), postfix(postfix)
{
   // Calling previous functions will throw asserts. Do nothing here!
}

Date::~Date()
{
   // Destroy everything!
}

/*****************************************************
 * VALIDATEDATE:  Make sure everything is arranged properly.
 *   INPUT  none
 *   OUTPUT none
 *****************************************************/
void Date::validateDate()
{

   // Handle days first.
   
   // Check to make sure you can't adjust to years first
   while (day >= 365)
   {
      if (isLeapYear(year))
      {
         day -= 366;    // If leap year, subtract 365. Day cannot be 0!
         year++;        // Increment year by 1.
      }
      else
      {
         day -= 365;    // If not leap year, subtract 364. Day cannot be 0!
         year++;        // increment year by 1.
      }
   }
   
   // Offset by one for the day(s) already there.
   while (day <= -364)
   {

      if (isLeapYear(year))
      {
         day += 365;    // If leap year, add 365. Day cannot be 0!
         year--;        // Decrement year by 1.
      }
      else
      {
         day += 364;    // If not leap year, add 364. Day cannot be 0!
         year--;        // Decrement year by 1.
      }
   }
   
   // If not years, check to see if months can be adjusted
   while (day > 31)
   {
      switch (month)
      {
         case 1:              // Months with 31 days, increment month by 1.
         case 3:
         case 5:
         case 7:
         case 8:
         case 10:
         case 12:
            day -= 31;
            month++;
            break;
         case 4:              // Months with 30 days, increment month by 1.
         case 6:
         case 9:
         case 11:
            day -= 30;
            month++;
            break;
         case 2:              // February is special. 28 or 29 days.
            if (isLeapYear(2000 + year))
            {
               day -= 29;
               month ++;
               break;
            }
            else
            {
               day -= 28;
               month ++;
               break;
            }
         case 13:             // While there is no 13th month, catch overflow.
            day -= 31;        // Subtract 31 from day.
            month = 1;        // Set month to January.
            break;
      }
   }
   
   // Make sure the day is not less than 0 .... day <= 0
   while (day <=  0)
   {
      if (day == 0)
      {
         month--;                // Start by decrementing the month by one.
         switch(month)           // Check the month after decrement to assign days.
         {
            case 0:              // While no month 0. Reset to December. 
               month = 12;       // Set month to December
               day = 31;        // Add 31 to the days.
               year--;           // When month hits 0, decrement the year by 1.
            case 1:              // Months with 31 days.
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
               day = 31;
               break;
            case 4:              // Months with 30 days.
            case 6:
            case 9:
            case 11:
               day = 30;
               break;
            case 2:              // February is special 28 or 29 days. 
               if (isLeapYear(2000 + year))
               {
                  day = 29;
                  break;
               }
               else
               {
                  day = 28;
                  break;
               }
         }
      }
      else
      {
         
         month--;                // Start by decrementing the month by one.
         
         switch(month)           // Check the month after decrement to assign days.
         {
            case 0:              // While no month 0. Reset to December. 
               month = 12;       // Set month to December
               day += 31;        // Add 31 to the days.
               year--;           // When month hits 0, decrement the year by 1.
            case 1:              // Months with 31 days.
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
               day += 31;
               break;
            case 4:              // Months with 30 days.
            case 6:
            case 9:
            case 11:
               day+= 30;
               break;
            case 2:              // February is special 28 or 29 days. 
               if (isLeapYear(2000 + year))
               {
                  day += 29;
                  break;
               }
               else
               {
                  day += 28;
                  break;
               }
         }
      }
   }
   
   // Check months next
   // Make sure the month does not overflow
   while(month > 12)
   {
      year++;                 // If greater than twelve, increment the year by 
      month -=12;             // one and subtract 12.
   }

   // Make sure the month does not drop below 0.
   while(month <= 0)
   {
      year--;                 // If month below or at 0, decrement the year by
      month += 12;            // one and add 12.  
   }
   
   // Assert the values just to make sure they are alright.
   assert(year > 1753 && year < 2500);
   assert(month > 0 && month < 13);
   assert(day > 0 && month <= 31);
   
   // Assign the fixed values to the object. 
   setDate(year, month, day);
}

/*****************************************************
 * DISPLAY.  Determine how the date should be displayed.
 *   INPUT  none
 *   OUTPUT none
 *****************************************************/
void Date::display() const
{
   if(postfix == 1)   // Check to see if days are only supposed to be displayed.
      displayDays();
   else if (isShort)  // Check to see if formate MM/DD/YYY.
      displayShort(); 
   else               // Check to see if format nth day of year.
      displayLong();
}

/*****************************************************
 * DISPLAYDAYS.  Output the total number of days from 1/1/2000.
 *   INPUT  none
 *   OUTPUT none
 *****************************************************/
void Date::displayDays() const
{
   int tempDays = 0;
   
   if (isLeapYear(2000 + year))
   {
      tempDays = getDaysLeft() + (year * 366);
   }
   else
   {
      tempDays = getDaysLeft() + (year * 365);
   }
   
   cout << tempDays;
}

/*****************************************************
 * DISPLAYSHORT.  Output the date in "MM/DD/YYYY" format.
 *   INPUT  none
 *   OUTPUT none
 *****************************************************/
void Date::displayShort() const
{
   assertDate();
   cout << month << "/" << day << "/" << year;
}

/*****************************************************
 * DISPLAYLONG.  Output the date in "nth day of year" format.
 *   INPUT  none
 *   OUTPUT none
 *****************************************************/
void Date::displayLong() const
{
   assertDate();
   
   // day
   cout << day;
   switch (day)
   {
      case 1:
      case 21:
      case 31:
         cout << "st";
         break;
      case 2:
      case 22:
         cout << "nd";
         break;
      case 3:
      case 23:
         cout << "rd";
         break;
      default:
         cout << "th";
   }

   // month
   const char MONTHS[12][10] =
      { "January", "February", "March",     "April",   "May",      "June",
        "July",    "August",   "September", "October", "November", "December"};

   cout << " of " << MONTHS[month - 1] << ", ";

   // year
   cout << year;
}

/*****************************************************
 * DAYS MONTH.  How many days are there in the current month?
 *   INPUT  month    the month we are inquiring about
 *          year     we only care about this when month == 2
 *   OUTPUT return   return the number
 *****************************************************/
int Date :: daysMonth(const int month, const int year) const
{
   if (month > 12 || month < 1)
   {
      assert(false);
      return 0;
   }

   const int DAYS[13] =
       /* JAN FEB MAR APR MAY JUN JUL AUG SEP OCT NOV DEC */
      { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   // special case the one leap month
   if (month == 2 && isLeapYear(year))
      return 29;

   assert(month > 0 && month < 13);
   return DAYS[month];
}

int Date::getDaysLeft() const
{
   int tempDay = day;
   int tempMonth = month;
   int tempYear = year;
   
   while (tempYear -1 > 0)
   {
      if (isLeapYear(2000 + tempYear))
      {
         tempDay += 366;
         tempYear--;
      }
      else
      {
         tempDay += 365;
         tempYear--;
      }
   }
   
   while (tempMonth > 0)
   {
      switch (tempMonth)
      {
         case 1:
         case 3:
         case 5:
         case 7:
         case 8:
         case 10:
         case 12:
            tempDay += 31;
            break;
         case 4:
         case 6:
         case 9:
         case 11:
            tempDay += 30;
            break;
         case 2:
            if (isLeapYear(2000 + year - 1))
            {
               tempDay += 29;
               break;
            }
            else
            {
               tempDay += 28;
               break;
            }
      }
      tempMonth--;
   }
   
   return tempDay;
}

/***********************************************
 * IS LEAP YEAR.  Is the passed year a leap year?
 *   INPUT   year    The current year
 *   OUTPUT  return  True if we are in a leap year
 **********************************************/
bool Date :: isLeapYear(const int year) const
{
   // no leap years before 1753
   assert(year >= 1753);

   // what, are you Buck Rogers?
   assert(year < 2500);

   // Not a leap year if not evenly divisible by 4
   // This will eliminate 75% of all years
   if (year % 4 != 0)
      return false; // 2001, 2002, 2003, 2005, etc.
   assert(year % 4 == 0);

   // Is a leap year if not divisible by 100
   // This will eliminate 96% of the rest
   if (year % 100 != 0)
      return true; // 1996, 2004, 2008, 2012, etc.
   // We better be 1800, 1900, 2000, 2100 at this point
   assert(year % 100 == 0);

   // Is a leap year if on the quad century
   if (year % 400 == 0)
      return true; // 1600, 2000, 2400, etc.
   // It better be something like 1800, 1900, 2100, etc.
   assert(year % 400 != 0);

   // the balance better be 1900, 1800, etc.
   assert(year == 1800 || year == 1900 || year == 2100 || year == 2200);
   return false;
}

/************************************************
 * ASSERT DATE.  Validate date
 *   INPUT date: the date to be validated
 ***********************************************/
void Date :: assertDate() const
{
   string file = __FILE__;
   int line = __LINE__;
   // validate the year.  Keep it real
   if (year < 1753 || year > 2500)
   {
      cerr << "Assert: " << file << ": " << line
           << ": date.year=" << year << " outside valid range\n";
      exit(1);
   }

   // valide the month
   if (month < 1 || month > 12)
   {
      cerr << "Assert: " << file << ": " << line
           << ": date.month=" << month << " outside valid range\n";
      exit(1);
   }

   // finally the day.
   if (day < 1
       || day > daysMonth(month, year))
   {
      cerr << "Assert: " << file << ": " << line
           << ": date.day=" << day << " outside valid range\n";
      exit(1);
   }
}
