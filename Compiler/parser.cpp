#include <iostream>

#include "abstractSyntaxTree.h"

using namespace std;

class Parser {
public:

  // Constructor
  Parser(string inFile,
         string outFile);
  ~Parser();

  // Variables

  // Functions
  void iadd(Variable &a,
            Variable &b,
            Variable &r);

private:

  // Variables
  // Files
  string inFile, outFile;
  // Address
  int returnAdd, currentAdd;
  // Jasmin strings
  string addStr,
         storeStr, loadStr, ldcStr;

  // Functions
  void ldc(Variable &a);
  void istore(Variable &a);
  void iload(Variable &a);
};

// Constructor
Parser::Parser(string inFile, string outFile) {
  this->inFile  = inFile;
  this->outFile = outFile;

  this->returnAdd  = 0;
  this->currentAdd = 0;
}

Parser::~Parser() {}

void Parser::iadd(Variable &a, Variable &b, Variable &r) {
  iload(a);
  iload(b);
  addStr = "\t\t iadd\n";
  printf("%s", addStr.c_str());
  istore(r);
}

// Push value to stack so it can be saved
void Parser::ldc(Variable &a) {
  ldcStr = "\t\t ldc " + string(a.value) + "\n";
  printf("%s", ldcStr.c_str());
}

// Gets the value from the stack and save it to the address
void Parser::istore(Variable &a) {
  if (a.address == -1) {
    ldc(a);
    a.address = ++currentAdd;
  }
  storeStr = "\t\t istore " + to_string(a.address) + "\n";
  printf("%s", storeStr.c_str());
}

// Puts the value into the stack from the address
void Parser::iload(Variable &a) {
  if (a.address == -1) {
    istore(a);
    // printf("a.address: %i, currentAdd: %i\n", a.address, currentAdd);
  }
  loadStr = "\t\t iload " + to_string(a.address) + "\n";
  printf("%s", loadStr.c_str());
}

// Main function for the program
int main(void) {
  Parser   p("../C-Program/add_num.c", "../C-Program/add_num.j");
  Variable a, b;

  a.type  = Int;
  b.type  = Int;
  a.name  = "x";
  b.name  = "y";
  a.value = "10";
  b.value = "1";
  // a.address = Int;
  // b.address = Int;
  p.iadd(a, b, a);

  return 0;
}
