#ifndef MODULUS_H
#define MODULUS_H

#include "../Operation.h"

class Modulus : public Operation {
private:
  float val1;
  float val2;

public:
  float Evaluate() override;
  Modulus(float val1, float val2);
};

#endif // MODULUS_H
