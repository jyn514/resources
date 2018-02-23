#include "Utils.h"

static const std::string TAG = "Utils: ";
const std::string Utils::WHITESPACE = " \n\t\r";

// ifstream Utils::inStream; // deprecated
// ofstream Utils::outStream; // deprecated
std::ofstream Utils::logStream;
std::ostringstream Utils::oss;
std::stringstream Utils::ss;

/****************************************************************
 * Constructor.
**/
Utils::Utils()
{
}
/****************************************************************
 * Destructor.
**/
Utils::~Utils()
{
}

/****************************************************************
 * General functions.
**/
/****************************************************************
 * Check for the correct number of arguments.
 *
 * Parameters:
 *   howMany - the expected number of arguments
 *   argc - the usual 'argc' of command line information
 *   argv - the usual 'argv' of command line information
 *   usage - the 'usage' message to display on error
 * Return: none
**/
void Utils::CheckArgs(const int howMany, const int argc,
                      char *argv[], const std::string usage)
{
  if(argc != howMany + 1)
  {
//    std::cout << TAG << "incorrect argument count\n";
    std::cout << TAG << "usage: " << argv[0] << " " << usage << std::endl;
    exit(1);
  }
}

/****************************************************************
 * Close an input stream.
 *
 * Parameters:
 *   inStream - the 'ifstream' input stream by reference
 * Return: none
**/
void Utils::FileClose(std::ifstream& inStream)
{
  std::cout << TAG << "close the input file\n";
  inStream.close();
  std::cout << TAG << "the input file was closed\n";
}

/****************************************************************
 * Close an output stream.
 *
 * Parameters:
 *   outStream - the 'ofstream' output stream by reference
 * Return: none
**/
void Utils::FileClose(std::ofstream& outStream)
{
  std::cout << TAG << "close the output file\n";
  outStream.close();
  std::cout << TAG << "the output file was closed\n";
}

/****************************************************************
 * Open an input stream.
 *
 * Parameters:
 *   inStream - the 'ifstream' input stream by reference
 *   fileName - the name of the file to be opened
 * Return: none
**/
void Utils::FileOpen(std::ifstream& inStream, std::string fileName)
{
  std::cout << TAG << "open the input file '" << fileName << "'\n";
  inStream.open(fileName.c_str());
  if(inStream.fail())
  {
    std::cout << TAG << "open failed for '" << fileName << "'\n";
    exit(0);
  }
  std::cout << TAG << "open succeeded for '" << fileName << "'\n";
}

/****************************************************************
 * Open an output stream.
 *
 * Parameters:
 *   outStream - the 'ofstream' output stream by reference
 *   fileName - the name of the file to be opened
 * Return: none
**/
void Utils::FileOpen(std::ofstream& outStream, std::string fileName)
{
  std::cout << TAG << "open the output file '" << fileName << "'\n";
  outStream.open(fileName.c_str());
  if(outStream.fail())
  {
    std::cout << TAG << "open failed for '" << fileName << "'\n";
    exit(0);
  }
  std::cout << TAG << "open succeeded for '" << fileName << "'\n";
}

/****************************************************************
 * Open the static logfile stream.
 *
 * Parameters:
 *   fileName - the name of the file to associate with
 *              the 'Utils::logStream'
 * Return: none
**/
void Utils::LogFileOpen(std::string fileName)
{
  std::cout << TAG << "open the logfile '" << fileName << "'\n";
  logStream.open(fileName.c_str());
  if(logStream.fail())
  {
    std::cout << TAG << "open failed for '" << fileName << "'\n";
    exit(0);
  }
  std::cout << TAG << "open succeeded for '" << fileName << "'\n";
}

/****************************************************************
 * These are the overloaded formatting functions that all return
 * a 'string' value after having formatted the first argument.
 * 
 * We have the following formatting:
 *   'char*' to a 'string' 
 *   'char*' to a 'string' of 'width' (default right) 
 *   'char*' to a 'string' of 'width' (left or right, default right) 
 *
 *   'string' to a 'string' 
 *   'string' to a 'string' of 'width' (default right) 
 *   'string' to a 'string' of 'width' (left or right, default right) 
 *
 *   'short'     to a 'string'
 *   'short'     to a 'string' of 'width'
 *   'int'       to a 'string'
 *   'int'       to a 'string' of 'width'
 *   'UINT'      to a 'string'
 *   'UINT'      to a 'string' of 'width'
 *   'LONG'      to a 'string'
 *   'LONG'      to a 'string' of 'width'
 *
 *   'double' to a 'string'
 *   'double' to a 'string' of 'width'
 *   'double' to a 'string' of 'width' and 'precision'
 *
**/
/****************************************************************
 * String-ify a 'char*' array, without width formatting.
 *
 * Parameters:
 *   value - the 'char*' variable to be converted and formatted.
 * Return: the string-ified version of 'value'
**/
std::string Utils::Format(const char* value)
{
  Utils::oss.str("");
  Utils::oss << std::string(value);
  return oss.str();
}

/****************************************************************
 * String-ify a 'char*' array, with width formatting.  This
 * uses the default justification on the left.
 *
 * Parameters:
 *   value - the 'char*' variable to be converted and formatted.
 *   width - the width of the output field.
 * Return: the string-ified version of 'value'
**/
std::string Utils::Format(const char* value, const int width)
{
  Utils::oss.str("");
  Utils::oss << std::setw(width) << std::string(value);
  return oss.str();
}

/****************************************************************
 * String-ify a 'char*' array, with width formatting and with
 * specified justification.
 *
 * Parameters:
 *   value - the 'char*' variable to be converted and formatted.
 *   width - the width of the output field.
 *   justify - desired justification, either 'right' or 'left'
 * Return: the string-ified version of 'value'
**/
std::string Utils::Format(const char* value, const int width,
                          const std::string justify)
{
  Utils::oss.str("");

  if("left" == justify)
  {
    Utils::oss.setf(std::ios::left, std::ios::adjustfield);
    Utils::oss << std::setw(width) << std::string(value);
  }
  else if("right" == justify)
  {
    Utils::oss.setf(std::ios::right, std::ios::adjustfield);
    Utils::oss << std::setw(width) << std::string(value);
  }
  else
  {
    Utils::oss << std::setw(width) << std::string(value);
  }
  return oss.str();
}

/****************************************************************
 * String-ify a string, without width formatting and without
 * specified justification.  This is just a pass-through.
 *
 * Parameters:
 *   value - the 'string' variable to be converted and formatted.
 * Return: the string-ified version of 'value'
**/
std::string Utils::Format(const std::string value)
{
  return value;
}

/****************************************************************
 * String-ify a string, with width formatting but without
 * specified justification.
 *
 * Parameters:
 *   value - the 'string' variable to be converted and formatted.
 *   width - the width of the output field.
 * Return: the string-ified version of 'value'
**/
std::string Utils::Format(const std::string value, const int width)
{
  Utils::oss.str("");
  Utils::oss << std::setw(width) << value;
  return oss.str();
}

/****************************************************************
 * String-ify a 'string', with width formatting and with
 * specified justification.
 *
 * Parameters:
 *   value - the 'string' variable to be converted and formatted.
 *   width - the width of the output field.
 *   justify - desired justification, either 'right' or 'left'
 * Return: the string-ified version of 'value'
**/
std::string Utils::Format(const std::string value, const int width,
                          const std::string justify)
{
  Utils::oss.str("");
  if("left" == justify)
  {
    Utils::oss.setf(std::ios::left, std::ios::adjustfield);
    Utils::oss << std::setw(width) << value;
  }
  else if("right" == justify)
  {
    Utils::oss.setf(std::ios::right, std::ios::adjustfield);
    Utils::oss << std::setw(width) << value;
  }
  else
  {
    Utils::oss << std::setw(width) << value;
  }
  return oss.str();
}

/****************************************************************
 * String-ify a 'short', without width formatting and without
 * specified justification.
 *
 * Parameters:
 *   value - the 'short' variable to be converted and formatted.
 * Return: the string-ified version of 'value'
**/
std::string Utils::Format(const short value)
{
  Utils::oss.str("");
  Utils::oss << value;
  return oss.str();
}

/****************************************************************
 * String-ify a 'short', with width formatting and with
 * default justification on the right.
 *
 * Parameters:
 *   value - the 'short' variable to be converted and formatted.
 *   width - the width of the output field.
 * Return: the string-ified version of 'value'
**/
std::string Utils::Format(const short value, const int width)
{
  Utils::oss.str("");
  Utils::oss.setf(std::ios::right, std::ios::adjustfield);
  Utils::oss << std::setw(width) << value;
  return oss.str();
}

/****************************************************************
 * String-ify an 'int', without width formatting and without
 * specified justification.
 *
 * Parameters:
 *   value - the 'int' variable to be converted and formatted.
 * Return: the string-ified version of 'value'
**/
std::string Utils::Format(const int value)
{
  Utils::oss.str("");
  Utils::oss << value;
  return oss.str();
}

/****************************************************************
 * String-ify an 'int', with width formatting and with
 * default justification on the right.
 *
 * Parameters:
 *   value - the 'int' variable to be converted and formatted.
 *   width - the width of the output field.
 * Return: the string-ified version of 'value'
**/
std::string Utils::Format(const int value, const int width)
{
  Utils::oss.str("");
  Utils::oss.setf(std::ios::right, std::ios::adjustfield);
  Utils::oss << std::setw(width) << value;
  return oss.str();
}

/****************************************************************
 * String-ify a 'UINT', without width formatting and without
 * specified justification.
 *
 * Parameters:
 *   value - the 'UINT' variable to be converted and formatted.
 * Return: the string-ified version of 'value'
**/
std::string Utils::Format(const UINT value)
{
  Utils::oss.str("");
  Utils::oss << value;
  return oss.str();
}

/****************************************************************
 * String-ify a 'UINT', with width formatting and with
 * default justification on the right.
 *
 * Parameters:
 *   value - the 'UINT' variable to be converted and formatted.
 *   width - the width of the output field.
 * Return: the string-ified version of 'value'
**/
std::string Utils::Format(const UINT value, const int width)
{
  Utils::oss.str("");
  Utils::oss.setf(std::ios::right, std::ios::adjustfield);
  Utils::oss << std::setw(width) << value;
  return oss.str();
}

/****************************************************************
 * String-ify a 'LONG', without width formatting and without
 * specified justification.
 *
 * Parameters:
 *   value - the 'LONG' variable to be converted and formatted.
 * Return: the string-ified version of 'value'
**/
std::string Utils::Format(const LONG value)
{
  Utils::oss.str("");
  Utils::oss << value;
  return oss.str();
}

/****************************************************************
 * String-ify a 'LONG', with width formatting and with
 * default justification on the right.
 *
 * Parameters:
 *   value - the 'LONG' variable to be converted and formatted.
 *   width - the width of the output field.
 * Return: the string-ified version of 'value'
**/
std::string Utils::Format(const LONG value, const int width)
{
  int localWidth = static_cast<int>(width);
  Utils::oss.str("");
  Utils::oss.setf(std::ios::right, std::ios::adjustfield);
  Utils::oss << std::setw(localWidth) << value;
  return oss.str();
}

/****************************************************************
 * String-ify a 'double', without width formatting and without
 * specified precision.
 *
 * Parameters:
 *   value - the 'double' variable to be converted and formatted.
 * Return: the string-ified version of 'value'
**/
std::string Utils::Format(const double value)
{
  Utils::oss.str("");
  Utils::oss << value;
  return oss.str();
}

/****************************************************************
 * String-ify a 'double', with width formatting but without
 * specified precision.
 *
 * This will by default be justified on the left. It is not clear
 * that any choice of justification is better than any other for
 * this kind of formatting.
 *
 * Parameters:
 *   value - the 'double' variable to be converted and formatted.
 *   width - the width of the output field.
 * Return: the string-ified version of 'value'
**/
std::string Utils::Format(const double value, const int width)
{
  Utils::oss.str("");
  Utils::oss << std::setw(width) << value;

  std::string returnString = Utils::Format(oss.str(), width);
  return returnString;
}

/****************************************************************
 * String-ify a 'double', with width formatting and with
 * specified precision.
 *
 * With precision specified, we have a fixed location for the
 * decimal point and thus we should justify on the right. 
 *
 * Parameters:
 *   value - the 'double' variable to be converted and formatted.
 *   width - the width of the output field.
 *   precision - desired precision to the right of the point
 * Return: the string-ified version of 'value'
**/
std::string Utils::Format(const double value, const int width,
                          const int precision)
{
  Utils::oss.str("");
  Utils::oss << std::fixed << std::setprecision(precision) << std::setw(width)
             << value;

  std::string returnString = Utils::Format(oss.str(), width, "right");
  return returnString;
}

/****************************************************************
 * Replace blanks with another character.
 * This is to allow using an underscore to make a string one string
 * instead of having embedded blanks. 
 *
 * Parameters:
 *   what - the input 'string' to trim blanks from
 * Returns:
 *   the 'what' string less any leading or trailing blanks
**/
std::string Utils::replaceBlanks(std::string input, char c)
{
  std::string returnValue;

  returnValue = input;

  std::string::size_type pos = returnValue.find(" ");
  while(pos != std::string::npos)
  {
    returnValue[pos] = c;
    pos = returnValue.find(" ");
  }

  return returnValue;
}

/****************************************************************
 * Convert a string to an integer.
 *
 * Parameters:
 *   input - the input 'string' to convert from
 * Returns:
 *   the 'int' value of 'input'
**/
int Utils::stringToInteger(std::string input)
{
  bool isNegative;
  int returnValue = 0;
  const std::string digits = "0123456789";

//  Utils::logStream << TAG << "string '" << input << "'\n";
//  Utils::logStream.flush();
  isNegative = false;
  if("-" == input.substr(0,1))
  { 
//    Utils::logStream << TAG << "negative '" << input.substr(0,1) << "'\n";
//    Utils::logStream.flush();
    isNegative = true;
    input = input.substr(1);
  }
//  Utils::logStream << TAG << "now pos '" << input << "'\n";
//  Utils::logStream.flush();

  for(std::string::iterator iter = input.begin(); iter != input.end(); ++iter)
  {
    int digit = digits.find(*iter);
    if((0 > digit) || (9 < digit))
    {
      Utils::logStream << TAG << "ERROR: string '" << input
                       << "' not a number\n";
      Utils::logStream.flush();
      exit(0);
    }
    returnValue = 10*returnValue + digit;
  }

  if(isNegative) returnValue = -returnValue;

  return returnValue;
} // int Utils::stringToInteger(string input)

/****************************************************************
 * Convert a string to a LONG.
 *
 * Parameters:
 *   input - the input 'string' to convert from
 * Returns:
 *   the 'int' value of 'input'
**/
LONG Utils::stringToLONG(std::string input)
{
  LONG returnValue = 0L;
  const std::string digits = "0123456789";

  for(std::string::iterator iter = input.begin(); iter != input.end(); ++iter)
  {
    int digit = digits.find(*iter);
    if((0 > digit) || (9 < digit))
    {
      Utils::logStream << TAG << "ERROR: string '" << input
                       << "' not a number\n";
      Utils::logStream.flush();
      exit(0);
    }
    returnValue = 10*returnValue + digit;
  }

  return returnValue;
} // LONG Utils::stringToLONG(std::string input)

/****************************************************************
 * Call the timing function
 *
 * Parameters:
 *   timestring - the label to be put into the time log
 * Returns: the 'string' version of the timing log
**/
std::string Utils::timecall(const std::string timestring)
{
  char s[160];
  std::string returnValue;
  static bool firsttime = true;
  static double usercurrent = 0.0,userone = 0.0,usertwo = 0.0;
  static double systemcurrent = 0.0,systemone = 0.0,systemtwo = 0.0;
  static double cpupctone,cpupcttwo;
  static double TIMEsystemtotal,TIMEusertotal;
  static struct rusage rusage;
  static time_t TIMEtcurrent,TIMEtone,TIMEttotal = 0.0,TIMEttwo;

  if(firsttime)
  {
    firsttime = false;
    TIMEusertotal = 0.0;
    TIMEsystemtotal = 0.0;
    TIMEtone = time(0);
    TIMEttwo = time(0);
  }

  getrusage(RUSAGE_SELF,&rusage);

  usertwo = (double) rusage.ru_utime.tv_sec;
  usertwo += (double) rusage.ru_utime.tv_usec/1000000.0;
  systemtwo = (double) rusage.ru_stime.tv_sec;
  systemtwo += (double) rusage.ru_stime.tv_usec/1000000.0;

  usercurrent = usertwo - userone;
  systemcurrent = systemtwo - systemone;

  TIMEusertotal += usercurrent;
  TIMEsystemtotal += systemcurrent;

  TIMEttwo = time(0);
  TIMEtcurrent = TIMEttwo - TIMEtone;
  TIMEttotal += TIMEtcurrent;
  if(TIMEtcurrent != 0)
  {
    cpupctone = 100.0 * ((double)usercurrent+systemcurrent) /
                           ((double)(TIMEtcurrent));
    if(cpupctone > 100.0) cpupctone = 100.0;
  }
  else
  {
    cpupctone = 0.0;
  }

  if(TIMEttotal != 0)
  {
    cpupcttwo = 100.0 * ((double)TIMEusertotal+TIMEsystemtotal) /
                           ((double)(TIMEttotal));
    if(cpupcttwo > 100.0) cpupcttwo = 100.0;
  }
  else
  {
    cpupcttwo = 0.0;
  }

  returnValue = "";
  snprintf(s,80,"\nTIME***********************************************************************\n");
  returnValue += std::string(s);

  snprintf(s,80,"TIME CPU percent  %6.2f %6.2f                    %s",
             cpupctone,cpupcttwo,ctime(&TIMEttwo));
  returnValue += std::string(s);

  snprintf(s,80,"TIME %-15s %10.2f u   %10.2f s   Res:%12ld\n",
                 timestring.c_str(),usercurrent,systemcurrent, rusage.ru_maxrss);
  returnValue += std::string(s);

  snprintf(s,80,"TIME %-15s %10.2f u_t %10.2f s_t\n",
                 timestring.c_str(),TIMEusertotal,TIMEsystemtotal);
  returnValue += std::string(s);

  snprintf(s,80,"TIME***********************************************************************\n");
  returnValue += std::string(s);

  returnValue += "\n\n";

  userone = usertwo;
  systemone = systemtwo;
  TIMEtone = TIMEttwo;

  return returnValue;
} // std::string Utils::timecall(const std::string timestring)

/****************************************************************
 * Convert a string to all lowercase.
 *
 * Parameters:
 *   to - the input 'string' to convert 
 *   from - the output converted 'string'
 * Returns: none
**/
void Utils::toLower(std::string& to, const std::string from)
{
  static char c[1024];

  snprintf(c, 1024, "%s", from.c_str());
  for(UINT i = 0; i < from.length(); ++i)
  {
    if(isupper(c[i])) c[i] = tolower(c[i]);
  }
  to = std::string(c);
} // void Utils::toLower(std::string& to, const std::string from)

/****************************************************************
 * Trim away leading and trailing blanks.
 *
 * Parameters:
 *   what - the input 'string' to trim blanks from
 * Returns:
 *   the 'what' string less any leading or trailing blanks
**/
std::string Utils::trimBlanks(std::string what)
{
  int length;
  std::string returnValue;

  returnValue = what;

  // trim away leading blanks
  while(" " == returnValue.substr(0,1))
  {
    length = returnValue.length();
    returnValue = returnValue.substr(1,length);
  }

  // trim away trailing blanks
  if(!returnValue.empty())
  {
    length = returnValue.length();
    while(" " == returnValue.substr(length-1,1))
    {
      returnValue = returnValue.substr(0,length-1);
      length = returnValue.length();
    }
  }

  return returnValue;
} // std::string Utils::trimBlanks(std::string what)

/****************************************************************
 * General function for trimming whitespace from begin and end.
 *
 * Parameters:
 *   s - the input 'string' to trim blanks from
 * Returns:
 *   the 's' string less any leading or trailing whitespace
**/
std::string Utils::trim(std::string s)
{
  size_t foundPos = std::string::npos;
  std::string returnString = s;

#ifdef EBUG3
  Utils::logStream << TAG << "orig string: '" << returnString << "'\n";
  Utils::logStream.flush();
#endif

  foundPos = returnString.find_first_not_of(Utils::WHITESPACE);
#ifdef EBUG3
  Utils::logStream << TAG << "found first: " << foundPos << std::endl;
  Utils::logStream.flush();
#endif
  if(foundPos != std::string::npos)
  {
    returnString = s.substr(foundPos);
  }
#ifdef EBUG3
  Utils::logStream << TAG << "new string:  '" << returnString << "'\n";
  Utils::logStream.flush();
#endif

  foundPos = returnString.find_last_not_of(Utils::WHITESPACE);
#ifdef EBUG3
  Utils::logStream << TAG << "found last:  " << foundPos << std::endl;
  Utils::logStream.flush();
#endif
  if(foundPos != std::string::npos)
  {
    returnString = returnString.substr(0,foundPos+1);
  }
#ifdef EBUG3
  Utils::logStream << TAG << "new string:  '" << returnString << "'\n";
  Utils::logStream.flush();
#endif

  return returnString;
} // std::string Utils::trim(std::string s)

