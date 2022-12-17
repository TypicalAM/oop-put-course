#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "../Operation.h"

class Subtraction : public Operation {
private:
  float val1;
  float val2;

public:
  float Evaluate() override;
  Subtraction(float val1, float val2);
};

#endif // SUBTRACTION_H
