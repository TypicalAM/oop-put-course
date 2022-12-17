#include "../../../include/math/operations/Exponentiation.h"
#include <complex>

float Exponentiation::Evaluate() { return std::pow(val2, val1); }

Exponentiation::Exponentiation(float val1, float val2) {
  this->val1 = val1;
  this->val2 = val2;
}
