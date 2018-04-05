#include <stdio.h>
#include <iostream>
#include <fstream>

#include "abstractSyntaxTree.h"

// Class *classes;

Include  *includes;
Function *funcs;

std::string sym = "";

char ch;

int numberOfChars;

void getChar(std::ifstream& is);
void getSymbol(std::ifstream& is);
void getInclude(std::ifstream& is);

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

  default:
    std::cout << "Character read: " << ch << std::endl;
    break;
  }
  // getChar(is);
  // getSymbol(is);
}

void getInclude(std::ifstream& is) {
  for(int i = 0; i < 7; i++){
		getChar(is);
	}
	// while(ch =){
	//
	// }
}
