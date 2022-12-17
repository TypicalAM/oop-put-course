#include "../../../include/math/operations/LogicalAND.h"
#include <cmath>

float LogicalAND::Evaluate() {
  return (int)std::round(val2) & (int)std::round(val1);
}

LogicalAND::LogicalAND(float val1, float val2) {
  this->val1 = val1;
  this->val2 = val2;
}
