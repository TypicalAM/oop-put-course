#ifndef LOGICAL_OR_H
#define LOGICAL_OR_H

#include "../Operation.h"

class LogicalOR : public Operation {
private:
  float val1;
  float val2;

public:
  float Evaluate() override;
  LogicalOR(float val1, float val2);
};

#endif // LOGICAL_OR_H
