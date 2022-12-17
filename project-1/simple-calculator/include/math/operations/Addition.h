#ifndef ADDITION_H
#define ADDITION_H

#include "../Operation.h"

class Addition : public Operation {
private:
  float val1;
  float val2;

public:
  float Evaluate() override;
  Addition(float val1, float val2);
};

#endif // ADDITION_H
