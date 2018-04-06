#include <iostream>
#include <fstream>

#include "parser.h"

using namespace std;

// Constructor
Parser::Parser(string outFile) {
  // this->inFile  = inFile;
  this->outFile = outFile;

  myfile.open(outFile);

  this->returnAdd  = 0;
  this->currentAdd = 0;

  myfile << ".class public add_num\n";
  myfile << ".super java/lang/Object\n";
  myfile << ".method public ()V\n";
  myfile << "\taload_0\n";
  myfile << "\tinvokespecial java/lang/Object/()V\n";
  myfile << "\treturn\n";
  myfile << ".end method\n";
  printToScreenSetup();

  myfile << ".method public static main([Ljava/lang/String;)V\n";
  myfile << "\t.limit stack  150\n";
  myfile << "\t.limit locals 150\n";
  myfile << "\tLmain:\n";
}

Parser::~Parser() {
  myfile << "\t\treturn\n";
  myfile << ".end method";
  myfile.close();
}

// void Parser::setOutFile(string outFile){
//   this->outFile = outFile;
// }

// Push value to stack so it can be saved
void Parser::ldc(Variable& a) {
  ldcStr = "\t\tldc " + string(a.value) + "\n";
  printToFile(ldcStr.c_str());
  istore(a);
}

void Parser::iadd(Variable& a, Variable& b, Variable& r) {
  iload(a);
  iload(b);
  addStr = "\t\tiadd\n";
  printToFile(addStr.c_str());
  istore(r);
}

// Gets the value from the stack and save it to the address
void Parser::istore(Variable& a) {
  if (a.address == -1) {
    a.address = ++currentAdd;
  }
  storeStr = "\t\tistore " + to_string(a.address) + "\n";
  printToFile(storeStr.c_str());
}

// Puts the value into the stack from the address
void Parser::iload(Variable& a) {
  if (a.address == -1) {
    istore(a);
  }
  loadStr = "\t\tiload " + to_string(a.address) + "\n";
  printToFile(loadStr.c_str());
}

void Parser::printToScreen(Variable& a) {
  iload(a);
  myfile << "\t\tinvokestatic add_num.print(I)V\n";
}

void Parser::printToScreenSetup() {
  myfile << ".method public static print(I)V\n";
  myfile << "\t.limit locals 5\n";
  myfile << "\t.limit stack 5\n";
  myfile << "\tiload 0\n";
  myfile << "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n";
  myfile << "\tswap\n";
  myfile << "\tinvokevirtual java/io/PrintStream/print(I)V\n";
  myfile << "\treturn\n";
  myfile << ".end method\n";
}

void Parser::printToFile(string str) {
  myfile << str;
}
