#include "../../../include/math/operations/LogicalOR.h"
#include <cmath>

float LogicalOR::Evaluate() {
  return (int)std::round(val2) | (int)std::round(val1);
}

LogicalOR::LogicalOR(float val1, float val2) {
  this->val1 = val1;
  this->val2 = val2;
}
