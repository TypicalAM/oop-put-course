#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "../Operation.h"

class Multiplication : public Operation {
private:
  float val1;
  float val2;

public:
  float Evaluate() override;
  Multiplication(float val1, float val2);
};

#endif // MULTIPLICATION_H
