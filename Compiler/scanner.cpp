#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

#include "parser.cpp"

// #include "abstractSyntaxTree.h"

using namespace std;

// Class *classes;

Include  *includes;
Function *funcs;

string SolidString = "";

char ch;

int numberOfChars;

void getChar(std::ifstream& is);
void getSymbol(std::ifstream& is);
// void getInclude(std::ifstream& is);
void getUntilChar(std::ifstream& is, char i_ch);
// int CompareChar(std::ifstream& is, char i_ch, char j_ch);

string getDigitFromString(string input);
Parser   p("../C-Program/add_num.c", "../C-Program/add_num.j");
Variable myVariables[4];
int varCounter =0;

bool inTheFunction = false;

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
    is.get(ch);
    if (is.fail()) ch = '\0';
    // debugging purposes only
    // else std::cout << "Character read: " << ch << std::endl;
  }
}

void getSymbol(std::ifstream& is) {

  if (ch == '{') inTheFunction = true;

  if (!inTheFunction){

    getChar(is);
    // break beacuse we are not in the function yet
    getSymbol(is);
  }

  switch (ch) {

    case  0:
    std::exit(EXIT_FAILURE);

    /* the following is commented out because we are currently only concerned with keywords that appear inside functions, and "include" doesn't */

    // case '#':
    //   getChar(is);
    // 	getUntilChar(is, ' ');
    //   std::cout << "  KEYWORD:  " << SolidString << std::endl;
    //   SolidString = "";
    //   break;

    /* anything incased in "<>" will be considered of file type and should be extracted as such*/

    // case '<':
    //   getChar(is);
    //   getUntilChar(is, '>');
    //   std::cout << "  FILE:     " << SolidString << std::endl;
    //   // TODO: take variable SoldiString (holds the name of an include file)
    //   SolidString = "";
    //   break;

    case 'c':
    getUntilChar(is, ' ');
    if (SolidString == "char") {
      std::cout << "  TYPE:       " << SolidString << std::endl;
      SolidString = "";
      getChar(is);

      getUntilChar(is, ' ');
      // getChar(is);
      std::cout << "  NAME:       " << SolidString << std::endl;

    }

    SolidString = "";
    break;

    case 'p':

    getUntilChar(is, '(');
    if (SolidString.find("print") != std::string::npos) {

      std::cout << "  FUNCTION:   " << SolidString << std::endl;
      SolidString = "";
      getChar(is);

      getUntilChar(is, ')');
      getChar(is);

      p.iadd(myVariables[0],myVariables[1], myVariables[2]);
      std::cout << "  INPUTS:   " << SolidString << std::endl;
      SolidString = "";
      getChar(is);
    }

    SolidString = "";
    break;

    case 'i' :
    getUntilChar(is, ' ');
    if (SolidString == "int") {

      myVariables[varCounter].type = Int;

      std::cout << "  TYPE:       " << SolidString << std::endl;
      SolidString = "";
      getChar(is);

      getUntilChar(is, ' ');

      myVariables[varCounter].name = SolidString.c_str();
      std::cout << "  NAME:       " << SolidString << std::endl;
      SolidString = "";

      getUntilChar(is, '=');
      getChar(is);
      SolidString = "";

      getUntilChar(is, ' ');
      getChar(is);
      SolidString = "";

      getUntilChar(is, ';');
      myVariables[varCounter].value = SolidString.c_str();
      std::cout << "  VALUE:      " << SolidString << std::endl;

      p.ldc(myVariables[varCounter]);
      varCounter++;
    }

    SolidString = "";
    break;

    case '/':
    getChar(is);
    getUntilChar(is, '/');
    std::cout << "  COMMENT:    " << SolidString << std::endl;
    // SoldiString (holds the contents of the comment)
    SolidString = "";
    break;

    case '"':
    getChar(is);
    getUntilChar(is, '"');
    std::cout << "  STRING:       " << SolidString << std::endl;
    // SoldiString (holds the contents of the comment)
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

// void getInclude(std::ifstream& is) {
//   for(int i = 0; i < 7; i++){
// 		getChar(is);
//
// 	}
// 	// while(ch =){
// 	//
// 	// }
// }

void getUntilChar(std::ifstream& is, char i_ch) {

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

/* The following is commented because we will not use it yet */
// int CompareChar(std::ifstream& is, char i_ch, char j_ch) {
//
//   for(int i = 0; i < 110; i++){
//     if  (ch == i_ch) {
//       return 1;
//     } if  (ch == j_ch) {
//       return 2;
//     } else {
//       // std::cout << "Character read: " << ch << std::endl;
//
//       SolidString += ch;
//       getChar(is);
//     }
//
//   }
//   // std::cout << "Word read: " << randa << std::endl;
//
//   return 0;
// }
