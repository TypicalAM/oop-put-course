#include "../../../include/math/operations/Subtraction.h"

float Subtraction::Evaluate() { return val2 - val1; }

Subtraction::Subtraction(float val1, float val2) {
  this->val1 = val1;
  this->val2 = val2;
}
