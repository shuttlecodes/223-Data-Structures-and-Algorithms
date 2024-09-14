//With out running the code (problem 3) in C++, write the output of the code
//Run it and check your outout

#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
   int hour;     // 0 - 23
   int minute;   // 0 - 59
   int second;   // 0 - 59
 
public:
   Time(int h = 0, int m = 0, int s = 0); //Constructor declaration - parameters with all 3 private variables
   int getHour() const;
   void setHour(int h);
   int getMinute() const;
   void setMinute(int m);
   int getSecond() const;
   void setSecond(int s);
   void setTime(int h, int m, int s);
   void print() const;
};

Time::Time(int h, int m, int s) { //Construction definition - initializes variables
   // Call setters to perform input validation
   setHour(h);
   setMinute(m);
   setSecond(s);
}

int Time::getHour() const { //member function definition (not used in this program)
   return hour; //returns hour (private variable)
}
 
void Time::setHour(int h) {  // with input validation
   if (h >= 0 && h <= 23) { //checking that the inputted h parameter is a valid hour number
      hour = h;             //if it is, then set private var hour
   } else {
      throw invalid_argument("Invalid hour! Hour shall be 0-23.");
            // need <stdexcept>
   }
}
 
int Time::getMinute() const {
   return minute;
}
 
void Time::setMinute(int m) {
   if (m >= 0 && m <= 59) { //check if the inputted m is a valid minute number
      minute = m;           //if so, then set the member variable minute to be equal to m
   } else {
      throw invalid_argument("Invalid minute! Minute shall be 0-59.");
            // need <stdexcept>
   }
}
 
int Time::getSecond() const {
   return second;
}
 
void Time::setSecond(int s) {
   if (s >= 0 && s <= 59) {
      second = s;
   } else {
      throw invalid_argument("Invalid second! Second shall be 0-59.");
            // need <stdexcept>
   }
}
 
void Time::setTime(int h, int m, int s) {
   // Call setters to validate inputs
   setHour(h);
   setMinute(m);
   setSecond(s);
}
 
void Time::print() const {//unchanging bc constant
   cout << setfill('0');
   cout << setw(2) << hour << ":" << setw(2) << minute << ":"
        << setw(2) << second << endl;
}
 
int main() {
   // Ordinary object
   Time t1(1, 2, 3);
   t1.print();  // 01:02:03
 
   // Object pointer - It's called ptrT1 and it's a type of pointer that points to objects of Time (in this case t1)
   Time* ptrT1 = &t1;
   (*ptrT1).print(); // 01:02:03 - print out the value
   ptrT1->print();   // 01:02:03 - this is an alternate version of prev line, using arrow operator
      // anObjectPtr->member is the same as (*anObjectPtr).member
 
   // Object reference - making another object, initializing the same as t1
   Time& refT1 = t1; // refT1 is an alias to t1
   refT1.print();    // 01:02:03
 
   // Dynamic allocation - made another pointer AND initialize these values
   Time* ptrT2 = new Time(4, 5, 6); // allocate dynamically
   ptrT2->print(); // 04:05:06
   delete ptrT2;   // deallocate - delete the box
 
   // Object Array
   Time tArray1[2];    // tArray1 is an array of Time with 2 elements - making an array of two Time objects
                       // Use default constructor for all elements
   tArray1[0].print();  // 00:00:00
   tArray1[1].print();  // 00:00:00
 
   Time tArray2[2] = {Time(7, 8, 9), Time(10)}; // Invoke constructor - calling the constructor to initialize three values for each Time object in the array
   tArray2[0].print();  // 07:08:09
   tArray2[1].print();  // 10:00:00
 
   Time* ptrTArray3 = new Time[2]; // ptrTArray3 is a pointer to Time
            // Dynamically allocate an array of Time with 2 elements via new[]
   ptrTArray3[0].print();  // 00:00:00
   ptrTArray3[1].print();  // 00:00:00
   delete[] ptrTArray3;    // Deallocate dynamic array via delete[]
 
   // C++11 syntax, compile with -std=c++0x
   Time* ptrTArray4 = new Time[2] {Time(11, 12, 13), Time(14)}; // Invoke constructor
   ptrTArray4->print();        // 11:12:13
   (ptrTArray4 + 1)->print();  // 14:00:00 - shows how incrementing a pointer that points to an array just makes the pointer point to the next element of the array
   delete[] ptrTArray4;
}