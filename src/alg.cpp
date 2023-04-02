// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int GetPriority(const char& operation) {
    switch (static_cast<int>(operation)) {
    case static_cast<int>(Operation::Add):
        return 2;
    case static_cast<int>(Operation::Subtract):
        return 2;
    case static_cast<int>(Operation::OpenBracket):
        return 0;
    case static_cast<int>(Operation::CloseBracket):
        return 1;
    case static_cast<int>(Operation::Multiply):
        return 3;
    case static_cast<int>(Operation::Divide):
        return 3;
    }
}
std::string infx2pstfx(std::string inf) {
  std::string post;
    TStack<char, 50> op;
    for (char j: inf) {
        if (j != '(' && j != ')' && j != '*' && j != '/' && j != '+' && j != '-') {
            post.push_back(j);
            post.push_back(' ');
        } else {
            if (GetPriority(j) == 0 || op.IsEmpty() || GetPriority(op.GetValue()) < GetPriority(j)) {
                op.Push(j);
            } else if (j == ')') {
                    while ('(' != op.GetValue()) {
                        post.push_back(op.Pop());
                        post.push_back(' ');
                    }
                    op.ForceRemove();
            } else {
                    bool sign = true;
                    while (sign && !op.IsEmpty()) {
                        sign = GetPriority(j) <= GetPriority(op.GetValue());
                        post.push_back(op.Pop());
                        post.push_back(' ');
                    }
                    op.Push(j);
                }
        }
    }
    while (!op.IsEmpty()) {
        post.push_back(op.Pop());
        post.push_back(' ');
    }
    post.pop_back();
    return post;
}

int eval(std::string pref) {
  int result=0;
    int Exploited;
    int Domain;
    TStack<int, 50> num;
    for (char j : pref) {
        if (j == '(' || j == ')' || j == '*' || j == '/' || j == '+' || j == '-') {
            switch (static_cast<int>(j)) {
            case static_cast<int>(Operation::Add):
                Exploited = num.Pop();
                Domain = num.Pop();
                num.Push(Exploited + Domain);
                break;
            case static_cast<int>(Operation::Subtract):
                Exploited = num.Pop();
                Domain = num.Pop();
                num.Push (Domain - Exploited);
                break;
            case static_cast<int>(Operation::Multiply):
                Exploited = num.Pop();
                Domain = num.Pop();
                num.Push(Exploited * Domain);
                break;
            case static_cast<int>(Operation::Divide):
                Exploited = num.Pop();
                Domain = num.Pop();
                num.Push(Domain / Exploited);
                break;
            }
        } else if (static_cast<int>(j) != 32 && static_cast<int>(j) != 40 && static_cast<int>(j) != 41) {
            num.Push(ConvertCharNumbers(j));
        }
    }
    if (!num.IsEmpty()) {
        result = num.Pop();
    }
    return result;
}
