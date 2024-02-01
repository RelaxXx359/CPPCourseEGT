// Date class definition.
#ifndef DATE_H
#define DATE_H

#include <iostream>
using std::ostream;

class Date
{
    //friend operator
   friend ostream &operator>>( ostream &, const Date & );
public:
    // default constructor
   Date( int m = 1, int d = 1, int y = 1900 );
    // set month, day, year
   void setDate( int, int, int );
    // prefix increment operator
   Date &operator--();
    // postfix increment operator
   Date operator--( int );
    // add days, modify object
   const Date &operator+=( int );
    // is date in a leap year?
   bool leapYear( int ) const;
    // is date at the end of month?
   bool endOfMonth( int ) const;
private:
    //variable
   int month;
   int day;
   int year;

    // array of days per month
   static const int days[];
    // utility function for incrementing date
   void helpIncrement();
}; // end class Date

#endif

