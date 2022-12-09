//
// Created by adam on 12/9/22.
//

#include "../../../include/math/expressions/NumericToken.h"

std::string NumericToken::Symbol() {
    return symbol;
}

NumericToken::NumericToken(std::string symbol) {
    this->symbol = symbol;
}
