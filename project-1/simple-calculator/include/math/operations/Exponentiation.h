#ifndef EXPONENTIATION_H
#define EXPONENTIATION_H

#include "../Operation.h"

class Exponentiation : public Operation {
private:
  float val1;
  float val2;

public:
  float Evaluate() override;
  Exponentiation(float val1, float val2);
};

#endif // EXPONENTIATION_H
