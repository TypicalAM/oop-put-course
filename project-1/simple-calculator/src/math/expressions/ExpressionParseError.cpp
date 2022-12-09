//
// Created by adam on 12/8/22.
//

#include "../../../include/math/expressions/ExpressionParseError.h"

char *ExpressionParseError::what() { return message; }

ExpressionParseError::ExpressionParseError(char *msg) : message(msg) {}
