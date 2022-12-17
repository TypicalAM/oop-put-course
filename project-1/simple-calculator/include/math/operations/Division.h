#ifndef DIVISION_H
#define DIVISION_H

#include "../Operation.h"

class Division : public Operation {
private:
  float val1;
  float val2;

public:
  float Evaluate() override;
  Division(float val1, float val2);
};

#endif // DIVISION_H
