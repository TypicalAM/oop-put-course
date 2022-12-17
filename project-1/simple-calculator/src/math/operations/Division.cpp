#include "../../../include/math/operations/Division.h"
#include "../../../include/math/expressions/ExpressionParseError.h"

float Division::Evaluate() {
  if (!val1)
    throw ExpressionParseError("division by zero!");
  return val2 / val1;
}

Division::Division(float val1, float val2) {
  this->val1 = val1;
  this->val2 = val2;
}
