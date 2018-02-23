/****************************************************************
 * Header for the 'Utils' class for utility programs.
 *
 * Author/copyright:  Duncan Buell
 * Date: 11 May 2013
 *
 * This code performs utility functions, including:
 * 1.  check for appropriate number of arguments and print an
 *     output 'usage' message if incorrect.
 * 2.  open/close input, output, and log files.
 * 3.  timing
**/

#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

// #define NDEBUG
#include <cassert>

typedef unsigned int UINT;
typedef int64_t LONG;

class Utils
{
public:
  static const std::string WHITESPACE;
/****************************************************************
 * Input, output, and log streams.
**/
//  static ifstream inStream; //deprecated
//  static ofstream outStream; //deprecated
  static std::ofstream logStream;

//  static stringstream utilsss(stringstream::in | stringstream::out);
  static std::stringstream ss;
  static std::ostringstream oss;

/****************************************************************
 * Constructors and destructors for the class. 
**/
  Utils();
  virtual ~Utils();

/****************************************************************
 * argument checker
**/
  static void CheckArgs(const int howMany, const int argc,
                        char *argv[], const std::string usage);

/****************************************************************
 * file open and close functions
**/
  static void FileClose(std::ifstream& inStream);
  static void FileClose(std::ofstream& outStream);
  static void FileOpen(std::ifstream& inStream, const std::string fileName);
  static void FileOpen(std::ofstream& outStream, const std::string fileName);
  static void InFileOpen(const std::string fileName);
//  static void OutFileOpen(const string fileName);
  static void LogFileOpen(const std::string fileName);

/****************************************************************
 * all sorts of formatting functions
**/
  static std::string Format(const char* value);
  static std::string Format(const char* value, const int width);
  static std::string Format(const char* value, const int width,
                            const std::string justify);

  static std::string Format(const std::string value);
  static std::string Format(const std::string value, const int width);
  static std::string Format(const std::string value, const int width,
                            const std::string justify);

  static std::string Format(const short value);
  static std::string Format(const short value, const int width);
  static std::string Format(const int value);
  static std::string Format(const int value, const int width);
  static std::string Format(const UINT value);
  static std::string Format(const UINT value, const int width);
  static std::string Format(const LONG value);
  static std::string Format(const LONG value, const int width);
  static std::string Format(const double value);
  static std::string Format(const double value, const int width);
  static std::string Format(const double value, const int width,
                            const int precision);

/****************************************************************
 * conversion functions
**/
  static int stringToInteger(std::string input);
  static LONG stringToLONG(std::string input);

/****************************************************************
 * miscellaneous utility functions
**/
//  static bool hasMoreData(ifstream& inStream);

  static std::string replaceBlanks(std::string input, char c);
  static std::string timecall(const std::string timestring);
  static void toLower(std::string& to, const std::string from);
  static std::string trimBlanks(std::string what);
  static std::string trim(std::string what);

private:
};

#endif /*UTILS_H_*/
