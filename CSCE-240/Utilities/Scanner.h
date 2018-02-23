/****************************************************************
 * Header for the 'Scanner' class.
 *
 * Author/copyright:  Duncan Buell
 * Date: 9 May 2013
 *
**/

#ifndef SCANNER_H_
#define SCANNER_H_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

#include "Utils.h"
#include "ScanLine.h"

// #define NDEBUG
#include <cassert>

typedef int64_t LONG;

class Scanner
{
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
  Scanner();
//  Scanner(ifstream& inStream);
//  Scanner(string inFileName);
  virtual ~Scanner();

/****************************************************************
 * Variables.
**/
  std::ifstream localStream;

/****************************************************************
 * General functions.
**/
  void close();
//  bool hasMoreData();
  bool hasNext();
//  char nextChar();
  double nextDouble();
  std::string next();
  std::string nextLine();
  void openFile(std::string fileName);
  int nextInt();
  LONG nextLONG();

private:
  ScanLine scanLine;
};

#endif // SCANNER_H_
