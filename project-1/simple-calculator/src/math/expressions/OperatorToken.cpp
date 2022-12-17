#include <utility>

#include "../../../include/math/expressions/OperatorToken.h"

std::string OperatorToken::Symbol() { return symbol; }

Associativity OperatorToken::Association() { return associativity; }

int OperatorToken::Compare(const OperatorToken &op) const {
  return precedence - op.precedence;
}

OperatorToken::OperatorToken(std::string symbol, Associativity associativity,
                             int precedence) {
  this->symbol = std::move(symbol);
  this->associativity = associativity;
  this->precedence = precedence;
}
