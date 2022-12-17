#include "../../../include/math/expressions/ExpressionParseError.h"

char *ExpressionParseError::what() { return message; }

ExpressionParseError::ExpressionParseError(char *msg) : message(msg) {}
