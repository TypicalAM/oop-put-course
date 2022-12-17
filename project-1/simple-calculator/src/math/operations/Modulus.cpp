#include "../../../include/math/operations/Modulus.h"
#include <cmath>

float Modulus::Evaluate() {
  return (int)std::round(val2) % (int)std::round(val1);
}

Modulus::Modulus(float val1, float val2) {
  this->val1 = val1;
  this->val2 = val2;
}
