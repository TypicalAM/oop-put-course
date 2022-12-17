#ifndef LOGICAL_AND_H
#define LOGICAL_AND_H

#include "../Operation.h"

class LogicalAND : public Operation {
private:
  float val1;
  float val2;

public:
  float Evaluate() override;
  LogicalAND(float val1, float val2);
};

#endif // LOGICAL_AND_H
