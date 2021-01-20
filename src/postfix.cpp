// Copyright 2020 A.SHT
#include "MyStack.h"
#include "postfix.h"

int priority(char val) {
  switch (val) {
    case '(':
      return 0;
    case ')':
      return 1;
    case '+':
    case '-':
      return 2;
    case '*':
    case '/':
      return 3;
    case ' ':
      return -1;
    default:
      return -2;
    }
}

std::string infix2postfix(std::string infix) {
  std::string postfix;
  MyStack<char> oper(100);
  for (int i = 0; i < infix.length(); i++) {
    if (infix[i] == ' ')
      continue;

    int prior = priority(infix[i]);
    if (prior == -2) {
      postfix += infix[i];
      if (infix[i+1] == '\0' || priority(infix[i+1]) != -2)
        postfix +=  ' ';
      continue;
    }

    if (oper.isEmpty() || prior == 0 || prior > priority(oper.get())) {
      oper.push(infix[i]);
      continue;
    }

    if (prior == 1) {
      while (oper.get() != '(')
        postfix = postfix + oper.pop() + ' ';
      oper.pop();
      continue;
    }

    if (prior > 1 && prior <= priority(oper.get())) {
      postfix = postfix + oper.pop() + ' ';
      oper.push(infix[i]);
    }
  }

  while (!oper.isEmpty())
    postfix = postfix + oper.pop() + ' ';
  postfix.pop_back();

  return postfix;
}
