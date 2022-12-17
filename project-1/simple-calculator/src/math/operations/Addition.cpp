#include "../../../include/math/operations/Addition.h"

float Addition::Evaluate() { return val1 + val2; }

Addition::Addition(float val1, float val2) {
  this->val1 = val1;
  this->val2 = val2;
}
