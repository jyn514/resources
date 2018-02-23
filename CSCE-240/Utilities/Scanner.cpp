#include "Scanner.h"

static const std::string TAG = "Scanner: ";

/****************************************************************
 * Constructor.
**/
Scanner::Scanner()
{
//  std::cout << TAG << "enter constructor" << std::endl;
  this->scanLine.openString("");
//  std::cout << TAG << "ScanLine has next? " << this->scanLine.hasNext() << std::endl;

  std::string theNext = this->scanLine.next();
//  std::cout << TAG << "ScanLine next? " << theNext << std::endl;
//  std::cout << TAG << "ScanLine has next? " << this->scanLine.hasNext() << std::endl;
//  std::cout << TAG << "leave constructor" << std::endl;
}

/****************************************************************
 * Destructor.
**/
Scanner::~Scanner()
{
}

/****************************************************************
 * Accessors and mutators.
**/

/****************************************************************
 * General functions.
**/
/****************************************************************
 * Function to close the stream.
**/
void Scanner::close()
{
  Utils::FileClose(this->localStream);
}

/****************************************************************
 * Function for testing for more data in the file.
 *
 * Returns:
 *   true if there is a 'next' of anything in the file. 
**/
bool Scanner::hasNext()
{
  bool returnValue = true;

//  std::cout << TAG << "enter hasNext" << std::endl;

  if (this->scanLine.hasNext())
  {
//    std::cout << TAG << "scanLine hasNext true" << std::endl;
//    std::cout << TAG << "leave hasNext" << std::endl;
    return true;
  }
  else
  {
    bool gotAnswer = false;
    while (!gotAnswer)
    {
//      std::cout << TAG << "scanLine hasNext false" << std::endl;
      std::string nextLine = this->nextLine();
//      std::cout << TAG << "next line is " << nextLine << std::endl;
      nextLine = Utils::trimBlanks(nextLine);
      if (0 == nextLine.length())
      {
//        std::cout << TAG << "next line exists and is blank " << nextLine << std::endl;
//        std::cout << TAG << "leave hasNext" << std::endl;
//        return false;
        if (this->localStream.eof()) return false;
      }
      else
      {
//        std::cout << TAG << "next line exists and is not blank " << nextLine << std::endl;
        scanLine.openString(nextLine);
//        std::cout << TAG << "leave hasNext" << std::endl;
        gotAnswer = true;
        return true;
      }
    } // while (!gotAnswer)

  }

//  std::cout << TAG << "leave hasNext" << std::endl;

  return returnValue;
} // bool Scanner::hasNext()

/****************************************************************
 * Function for returning a next token as a string.
 *
 * The definition of a 'token' is anything other than whitespace.
 * In this implementation, whitespace includes newline, carriage
 * return, and tab.
 *
 * We have two booleans to keep track of three states:
 *   have not yet found NWS (token beginning)
 *   have not yet found WS after finding NWS (token end)
 *
 * We read a character.
 * If there is no next character to be read
 *    Then we throw an error
 * While we are not at end of file:
 *    Test the char for NWS
 *    If NWS
 *       Set the bool that we have found NWS
 *       If we have found WS after NWS, 
 *          put back the NWS--it's the start of the next token
 *          break
 *       Else append the NWS to the token
 *    Else (i.e., if WS)
 *       If we have ever found NWS
 *          Set the bool that we have found WS after NWS
 *    Read the next character.
 *
 * Returns:
 *   the 'string' version of the next token.
**/
std::string Scanner::next()
{

  std::string returnValue = scanLine.next();

  return returnValue;
} // string Scanner::next()

/****************************************************************
 * Function for returning a next character.
 *
 * Returns:
 *   the next character in the file
char Scanner::nextChar()
{
  char c = this->localStream.get();
  return c;
} // char Scanner::nextChar()
**/

/****************************************************************
 * Function for returning a next 'double'.
 *
 * This function does not trap errors. Errors in converting from
 * 'string' to 'double' simply cause crashing.
 *
 * Returns:
 *   the next token in the file, parsed as a 'double'
**/
double Scanner::nextDouble()
{
  double returnValue;

  std::string nextToken = this->next();
  returnValue = atof(nextToken.c_str());

  return returnValue;
} // double Scanner::nextDouble()

/****************************************************************
 * Function for returning the next 'int' value.
 *
 * This function does not really trap errors. Errors in converting
 * from 'string' to 'int' simply cause crashing.
 *
 * Returns:
 *   the next token in the file, parsed as an 'int'
**/
int Scanner::nextInt()
{
  int returnValue;
  std::string nextToken;

  returnValue = 0;
  nextToken = this->next();

  returnValue = Utils::stringToInteger(nextToken);

  return returnValue;
} // int Scanner::nextInt()

/****************************************************************
 * Function for returning the rest of the line as a string.
 *
 * This is just a wrapper for the 'getline' function.
 * Note that this does not trim whitespace at the beginning
 * or at the end.
 *
 * Returns:
 *   the 'string' version of the rest of the line
**/
std::string Scanner::nextLine()
{
  std::string returnValue;

//  std::cout << TAG << "enter nextLine" << std::endl;

  if (scanLine.hasNext())
  {
    returnValue = scanLine.nextLine();
//    std::cout << TAG << "scanLine hasNext " << returnValue << std::endl;
  }
  else
  {
    getline(this->localStream, returnValue);
//    std::cout << TAG << "scanLine needed new line " << returnValue << std::endl;
  }

//  std::cout << TAG << "leave nextLine" << std::endl;
  return returnValue;
} // string Scanner::nextLine()

/****************************************************************
 * Function for returning the next 'LONG' value.
 *
 * This function does not really trap errors. Errors in converting
 * from 'string' to 'LONG' simply cause crashing.
 *
 * Returns:
 *   the next token in the file, parsed as an 'LONG'
**/
LONG Scanner::nextLONG()
{
  LONG returnValue;
  std::string nextToken;

  returnValue = 0;
  nextToken = this->next();

  returnValue = Utils::stringToLONG(nextToken);

  return returnValue;
} // LONG Scanner::nextLONG()

/****************************************************************
 * Function to open a file as a 'Scanner'.
**/
void Scanner::openFile(std::string fileName)
{
  Utils::FileOpen(this->localStream, fileName);
}

