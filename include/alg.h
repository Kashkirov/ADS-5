// Copyright 2021 NNTU-CS
#ifndef INCLUDE_ALG_H_
#define INCLUDE_ALG_H_

#include <string>
enum class Operation : char {
  Add = '+', 
  Subtract = '-', 
  Multiply = '*', 
  Divide = '/', 
  OpenBracket = '(', 
  CloseBracket = ')'
};
int GetPriority(const char& operation);
std::string infx2pstfx(std::string);
int eval(std::string);

#endif  // INCLUDE_ALG_H_
