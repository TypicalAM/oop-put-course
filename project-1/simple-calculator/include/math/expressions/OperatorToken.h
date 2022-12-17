#include <string>

#ifndef OPERATOR_TOKEN_H
#define OPERATOR_TOKEN_H

enum Associativity { LEFT, RIGHT };

class OperatorToken {
private:
  int precedence;
  std::string symbol;
  Associativity associativity;

public:
  int Compare(const OperatorToken &op) const;
  Associativity Association();
  std::string Symbol();
  OperatorToken(std::string symbol, Associativity associativity,
                int precedence);
};

#endif // OPERATOR_TOKEN_H
