#include <stdio.h>
#include <iostream>
#include <fstream>

#include "abstractSyntaxTree.h"

using namespace std;

// Class *classes;

Include  *includes;
Function *funcs;

string SolidString = "";

char ch;

int numberOfChars;

void getChar(std::ifstream& is);
void getSymbol(std::ifstream& is);
void getInclude(std::ifstream& is);
void getUntilChar(std::ifstream& is, char i_ch);

int  main(int argc, char *argv[]) {
  std::ifstream f(argv[1]);
  if (f.is_open()) {
    // get first character, get first symbol
    getChar(f);
    getSymbol(f);
  }
}

void getChar(std::ifstream& is) {
  if (is.eof()) ch = '\0';
  else {
    is >> ch;
    if (is.fail()) ch = '\0';
    // debugging purposes only
    // else std::cout << "Character read: " << ch << std::endl;
  }
}

void getSymbol(std::ifstream& is) {
  switch (ch) {
  case  0:
    std::exit(EXIT_FAILURE);

  case '#':
		getInclude(is);
    break;
  case '<':
    getUntilChar(is, '>');
    std::cout << "File read: " << SolidString << std::endl;
    // TODO: take variable SoldiString (holds the name of an include file)
    SolidString = "";
    break;
  case '/':
    getChar(is);
    getUntilChar(is, '/');
    std::cout << "Comment read: " << SolidString << std::endl;
    // TODO: take variable SoldiString (holds the name of an include file)
    SolidString = "";
    break;
  case '"':
    getChar(is);
    getUntilChar(is, '"');
    std::cout << "String read: " << SolidString << std::endl;
    // TODO: take variable SoldiString (holds the name of an include file)
    SolidString = "";
    break;
  default:
    // randa += ch;
    // std::cout << "Word read: " << randa << std::endl;
    // std::cout << "Character read: " << ch << std::endl;
    break;
  }
  getChar(is);
  getSymbol(is);
}

void getInclude(std::ifstream& is) {
  for(int i = 0; i < 7; i++){
		getChar(is);

	}
	// while(ch =){
	//
	// }
}

void getUntilChar(std::ifstream& is, char i_ch) {
  getChar(is);

  for(int i = 0; i < 110; i++){
    if  (ch == i_ch) {
      break;
    } else {
      // std::cout << "Character read: " << ch << std::endl;

      SolidString += ch;
      getChar(is);
    }

  }
  // std::cout << "Word read: " << randa << std::endl;

  return;

}
