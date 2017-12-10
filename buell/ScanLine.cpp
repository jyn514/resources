#include "ScanLine.h"

using namespace std;

static const string TAG = "ScanLine: ";

// ifstream Utils::inStream; // deprecated
// ofstream Utils::outStream; // deprecated
//ofstream ScanLine::zorklogStream;
//ostringstream ScanLine::zorkoss;
//stringstream ScanLine::zorkss;

//stringstream ScanLine::myss;

/****************************************************************
 * Constructor.
**/
ScanLine::ScanLine()
{
}
/****************************************************************
 * Destructor.
**/
ScanLine::~ScanLine()
{
}

/****************************************************************
 * General functions.
**/
/****************************************************************
 * Function 'hasMoreData'.
 *
 * Returns:
 *   true if there are ANY more characters in the input 'string'
**/
bool ScanLine::hasMoreData()
{
  bool returnValue = true;
#ifdef EBUGS
  Utils::logStream << TAG << "enter hasMoreData" << std::endl;
  Utils::logStream.flush();
#endif
  
  if(scanLineSS.eof())
  {
    returnValue = false;
  }

#ifdef EBUGS
  Utils::logStream << TAG << "leave hasMoreData '" << returnValue << "'" << std::endl;
  Utils::logStream.flush();
#endif

  return returnValue;
} 

/****************************************************************
 * Function 'hasNext'.
 *
 * Returns:
 *   true if there are ANY more characters in the input 'string'
**/
bool ScanLine::hasNext()
{
  bool returnValue = true;
#ifdef EBUGS
  Utils::logStream << TAG << "enter hasNext" << std::endl;
  Utils::logStream.flush();
#endif
  
  if(scanLineSS.eof())
  {
    returnValue = false;
  }

#ifdef EBUGS
  Utils::logStream << TAG << "leave hasNext '" << returnValue << "'" << std::endl;
  Utils::logStream.flush();
#endif

  return returnValue;
} 

/****************************************************************
 * Initialization. This because I can't make constructors work.
**/
void ScanLine::openString(std::string line)
{
  std::string token;

#ifdef EBUGS
  Utils::logStream << TAG << "enter openString '" << line << "'" << std::endl;
  Utils::logStream.flush();
#endif
  
  scanLineSS.clear();
  scanLineSS.str(line);

#ifdef EBUGS
  Utils::logStream << TAG << "leave openString" << std::endl;
  Utils::logStream.flush();
#endif
} 

/****************************************************************
 * Function 'next' to return the next string.
 *
 * The definition of a 'token' is anything other than whitespace.
 * In this implementation, whitespace includes newline, carriage
 * return, and tab.
 *
 * Returns:
 *   the 'string' versin of the next token
**/
string ScanLine::next()
{
  std::string token;

#ifdef EBUGS
  Utils::logStream << TAG << "enter next" << std::endl;
  Utils::logStream.flush();
#endif
  
  token = "";
  if(!scanLineSS.eof())
  {
    scanLineSS >> token;
  }

#ifdef EBUGS
  Utils::logStream << TAG << "leave next '" << token << "'" << std::endl;
  Utils::logStream.flush();
#endif

  return token;
} 

/****************************************************************
 * Function 'nextDouble' to return the next integer.
 *
 * This function does not really trap erorrs. Errors inconverting
 * from 'string' to 'int' simply cause crashing.
 *
 * Returns:
 *   the next token in the file, parsed as an 'int'
**/
double ScanLine::nextDouble()
{
  double localDouble = 0.0;

#ifdef EBUGS
  Utils::logStream << TAG << "enter nextDouble" << std::endl;
  Utils::logStream.flush();
#endif
  
  if(!scanLineSS.eof())
  {
    scanLineSS >> localDouble;
  }

#ifdef EBUGS
  Utils::logStream << TAG << "leave nextDouble '" << nextValue << "'" << std::endl;
  Utils::logStream.flush();
#endif

  return localDouble;
} 

/****************************************************************
 * Function 'nextInt' to return the next integer.
 *
 * This function does not really trap erorrs. Errors inconverting
 * from 'string' to 'int' simply cause crashing.
 *
 * Returns:
 *   the next token in the file, parsed as an 'int'
**/
int ScanLine::nextInt()
{
  int nextValue = 0;
  std::string token = "";

#ifdef EBUGS
  Utils::logStream << TAG << "enter nextInt" << std::endl;
  Utils::logStream.flush();
#endif
  
  if(!scanLineSS.eof())
  {
    scanLineSS >> token;
    nextValue = Utils::stringToInteger(token); 
  }

#ifdef EBUGS
  Utils::logStream << TAG << "leave nextInt '" << nextValue << "'" << std::endl;
  Utils::logStream.flush();
#endif

  return nextValue;
} 

/****************************************************************
 * Function 'nextLine' to return the rest of the line.
 *
 * This is just a wrapper for the 'getline' function.
 * Note that this does not trim whitespace at the beginning
 * or at the end.
 *
 * CAVEAT: We have put a max of 1024 characters that can be
 *         parsed with this function.
 *
 * Returns:
 *   the 'string' version of the rest of the line
**/
string ScanLine::nextLine()
{
  char xx[1025];
  std::string token;

#ifdef EBUGS
  Utils::logStream << TAG << "enter nextLine" << std::endl;
  Utils::logStream.flush();
#endif
  
  if (scanLineSS.eof())
  {
    token = "";
  }
  else
  {
    scanLineSS.getline(xx,1024);
    token = string(xx);
  }

#ifdef EBUGS
  Utils::logStream << TAG << "leave nextLine '" << token << "'" << std::endl;
  Utils::logStream.flush();
#endif

  return token;
} 

/****************************************************************
 * Function 'nextLONG' to return the next LONG.
 *
 * This function does not really trap errors. Errors in converting
 * from 'string' to 'LONG' simply cause crashing.
 *
 * Returns:
 *   the next token in the file, parsed as an 'LONG'
**/
LONG ScanLine::nextLONG()
{
  LONG nextValue = 0;
  std::string token = "";

#ifdef EBUGS
  Utils::logStream << TAG << "enter nextLONG" << std::endl;
  Utils::logStream.flush();
#endif
  
  if(!scanLineSS.eof())
  {
    scanLineSS >> token;
    nextValue = Utils::stringToLONG(token); 
  }

#ifdef EBUGS
  Utils::logStream << TAG << "leave nextLONG '" << nextValue << "'" << std::endl;
  Utils::logStream.flush();
#endif

  return nextValue;
} 

/****************************************************************
 * Test function to read.
void ScanLine::zork()
{
  string token;

#ifdef EBUGS
  Utils::logStream << TAG << "enter zork" << endl;
  Utils::logStream.flush();
#endif
  
// while(!scanLineSS.eof())
  while(this->hasNext())
  {
    token = next();

    Utils::logStream << TAG << "mytoken '" << token << "'" << endl;
    Utils::logStream.flush();
  }
  scanLineSS.clear();

#ifdef EBUGS
  Utils::logStream << TAG << "leave zork" << endl;
  Utils::logStream.flush();
#endif
} 
**/

