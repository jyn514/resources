#include <iostream>
using namespace std;
/****************************************************************
 * Example C++ program 1, CSCE 215, Fall 2009
 * Author: Pat O'Keefe, modified from original (Dr. Duncan Buell)
 * Date last modified: Aug 27 2009
 *
 * This program prompts the user for an input a value and
 * then prints a some message together with the
 * some number calculated from the original command line input. 
 *
 * Demos how to accept input from the command line and store it 
 * in a declared variable.  
 *
 * Notes:
 * You can put other helpful notes regarding your logic and program 
 * spec here.
 *    [note: All comments betweern "slash star" and "star slash" are 
 *     in fact comments and not
 *     processed by the c++ compiler as source code instructions.]
**/

int main( )
{
  const int someNumber = 3000; // this constant avoids magic numbers
  int someNumberFromUser; // the variable to hold the user's input

  cout << "Hello World!\n" 
       << "Please enter a whole number (less than 2^32)\n";

  cin >> someNumberFromUser;

  if(someNumberFromUser < someNumber) 
      cout << "Wow!\n"
           << "Your number is less than 3000! ";
  else
      cout <<  "Your number is " << someNumberFromUser << " which is " << someNumberFromUser - someNumber << " more than " << someNumber << ".\n"
           << "Have a great day!\n";

  return 0;
}



