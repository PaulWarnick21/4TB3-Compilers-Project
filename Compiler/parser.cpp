#include <iostream>

using namespace std;

class Parser {
public:

  // Constructor
  Parser(string inFile, string outFile);
  ~Parser();

  // Variables

  // Functions
  void add(Variable a, Variable b, Variable r);

private:

  // Variables
  // Files
  string inFile, outFile;
  // Address
  int returnAdd, currentAdd;
  // Jasmin strings
  string addStr, storeStr, loadStr;

  // Functions
  void store(Variable a);
  void load(Variable a);
};

// Constructor
Parser::Parser(string inFile, string outFile) {
  this->inFile = inFile;
  this->outFile = outFile;

  this->returnAdd = 0;
  this->currentAdd = 0;
}

Parser::~Parser() {}

void Parser::add(Variable a, Variable b, Variable r){
  load(a);
  load(b);

  store(r)
}

// Gets the value from the stack and save it to the address
void Parser::store(Variable a){
  currentAdd++;
  storeStr = "\t\t istore " + currentAdd + "\n";
}
// Puts the value into the stack from the address
void Parser::load(Variable a){
  loadStr = "\t\t iload " + currentAdd + "\n";
}

// Main function for the program
int main(void) {
  Parser p("../C-Program/add_num.c");
  p.add(int a, int b);

  return 0;
}
