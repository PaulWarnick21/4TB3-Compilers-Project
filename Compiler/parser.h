#include <iostream>
#include <fstream>

#include "abstractSyntaxTree.h"

using namespace std;

class Parser {
public:

  // Constructor
  Parser(string outFile);
  ~Parser();

  // Variables

  // Functions
  // void setInFile(string inFile);
  // void setOutFile(string outFile);
  void ldc(Variable& a);
  void iadd(Variable& a,
            Variable& b,
            Variable& r);
  void printToScreen(Variable& a);

private:

  // Variables
  // Files
  string inFile, outFile;
  // Address
  int returnAdd, currentAdd;
  // Jasmin strings
  string addStr, storeStr, loadStr, ldcStr;
  ofstream myfile;

  // Functions
  void printToScreenSetup();
  void printToFile(string str);
  void istore(Variable& a);
  void iload(Variable& a);
};
