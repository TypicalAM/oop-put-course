#include <utility>

#include "../../../include/math/expressions/NumericToken.h"

std::string NumericToken::Symbol() { return symbol; }

NumericToken::NumericToken(std::string symbol) {
  this->symbol = std::move(symbol);
}
