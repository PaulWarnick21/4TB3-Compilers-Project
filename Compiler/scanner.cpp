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

string extractedString = "";

char ch;

int numberOfChars;

void nextChar(std::ifstream& is);
void getSymbol(std::ifstream& is);
// void getInclude(std::ifstream& is);
void extractUntil(std::ifstream& is,
                  char           i_ch);
// int CompareChar(std::ifstream& is, char i_ch, char j_ch);

string getDigitFromString(string input);
Parser   p("./C-Program/add_num.j");
Variable myVariables[4];
int varCounter = 0;

bool inTheFunction = false;

int main(int argc, char *argv[]) {
  std::ifstream f(argv[1]);
  // p = new Parser ("../C-Program/add_num.j");
  // p.setOutFile("../C-Program/add_num.j");
  if (f.is_open()) {
    // get first character, get first symbol
    nextChar(f);
    getSymbol(f);
  }
}

void nextChar(std::ifstream& is) {
  if (is.eof()) ch = '\0';
  else {
    is.get(ch);
    if (is.fail()) ch = '\0';//std::exit(EXIT_FAILURE);
    // debugging purposes only
    // else std::cout << "Character read: " << ch << std::endl;
  }
}

void getSymbol(std::ifstream& is) {
  if (ch == '{') inTheFunction = true;

  if (!inTheFunction) {
    nextChar(is);
    // break beacuse we are not in the function yet
    getSymbol(is);
  }

  switch (ch) {
  case  0:
    // std::exit(EXIT_SUCCESS);
    break;

  /* the following is commented out because we are currently only concerned with
     keywords that appear inside functions, and "include" doesn't */

  // case '#':
  //   nextChar(is);
  //    extractUntil(is, ' ');
  //   std::cout << "  KEYWORD:  " << extractedString << std::endl;
  //   extractedString = "";
  //   break;

  /* anything incased in "<>" will be considered of file type and should be
     extracted as such*/

  // case '<':
  //   nextChar(is);
  //   extractUntil(is, '>');
  //   std::cout << "  FILE:     " << extractedString << std::endl;
  //   // take variable SoldiString (holds the name of an include file)
  //   extractedString = "";
  //   break;

  case 'c':
    extractUntil(is, ' ');
    if (extractedString == "char") {
      // std::cout << "  TYPE:       " << extractedString << std::endl;
      extractedString = "";
      nextChar(is);

      extractUntil(is, ' ');
      // nextChar(is);
      // std::cout << "  NAME:       " << extractedString << std::endl;
    }

    extractedString = "";
    nextChar(is);
    getSymbol(is);
    break;

  case 'p':

    extractUntil(is, '(');
    if (extractedString.find("print") != std::string::npos) {
      // std::cout << "  FUNCTION:   " << extractedString << std::endl;
      extractedString = "";
      nextChar(is);

      extractUntil(is, ')');
      nextChar(is);

      p.iadd(myVariables[0], myVariables[1], myVariables[2]);
      p.printToScreen(myVariables[2]);
      // std::cout << "  INPUTS:   " << extractedString << std::endl;
      extractedString = "";
      nextChar(is);
    }

    extractedString = "";
    nextChar(is);
    getSymbol(is);
    break;

  case 'i':
    extractUntil(is, ' ');
    if (extractedString == "int") {
      myVariables[varCounter].type = Int;

      // std::cout << "  TYPE:       " << extractedString << std::endl;
      extractedString = "";
      nextChar(is);

      extractUntil(is, ' ');

      myVariables[varCounter].name = extractedString.c_str();
      // std::cout << "  NAME:       " << extractedString << std::endl;
      extractedString = "";

      extractUntil(is, '=');
      nextChar(is);
      extractedString = "";

      extractUntil(is, ' ');
      nextChar(is);
      extractedString = "";

      extractUntil(is, ';');
      myVariables[varCounter].value = extractedString.c_str();
      std::cout << "  VALUE:      " << extractedString << std::endl;

      p.ldc(myVariables[varCounter]);
      varCounter++;
    }

    extractedString = "";
    nextChar(is);
    getSymbol(is);
    break;

  case '/':
    nextChar(is);
    extractUntil(is, '/');
    // std::cout << "  COMMENT:    " << extractedString << std::endl;
    // SoldiString (holds the contents of the comment)
    extractedString = "";
    nextChar(is);
    getSymbol(is);
    break;

  case '"':
    nextChar(is);
    extractUntil(is, '"');
    // std::cout << "  STRING:       " << extractedString << std::endl;
    // SoldiString (holds the contents of the comment)
    extractedString = "";
    nextChar(is);
    getSymbol(is);
    break;

  default:
    nextChar(is);
    getSymbol(is);
    // randa += ch;
    // std::cout << "Word read: " << randa << std::endl;
    // std::cout << "Character read: " << ch << std::endl;
    break;
  }
}

// void getInclude(std::ifstream& is) {
//   for(int i = 0; i < 7; i++){
//              nextChar(is);
//
//      }
//      // while(ch =){
//      //
//      // }
// }

void extractUntil(std::ifstream& is, char i_ch) {
  for (int i = 0; i < 110; i++) {
    if  (ch == i_ch) {
      break;
    } else {
      // std::cout << "Character read: " << ch << std::endl;

      extractedString += ch;
      nextChar(is);
    }
  }
  // std::cout << "Word read: " << randa << std::endl;
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
//       extractedString += ch;
//       nextChar(is);
//     }
//
//   }
//   // std::cout << "Word read: " << randa << std::endl;
//
//   return 0;
// }
