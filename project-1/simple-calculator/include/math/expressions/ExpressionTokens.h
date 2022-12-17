#include "NumericToken.h"
#include "OperatorToken.h"
#include <vector>

#ifndef EXPRESSION_TOKENS_H
#define EXPRESSION_TOKENS_H

class ExpressionTokens {
private:
  std::vector<OperatorToken> supportedOps;
  std::vector<NumericToken> supportedNums;

public:
  bool IsOperator(std::string &token);
  OperatorToken FromString(const std::string &token);
  float PerformOperation(float value1, float value2, std::string symbol);
  ExpressionTokens();
};

#endif // EXPRESSION_TOKENS_H
