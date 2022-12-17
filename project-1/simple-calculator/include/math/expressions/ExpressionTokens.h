//
// Created by adam on 12/9/22.
//

#include <vector>
#include "OperatorToken.h"
#include "NumericToken.h"

#ifndef CLION_EXPRESSIONTOKENS_H
#define CLION_EXPRESSIONTOKENS_H


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


#endif //CLION_EXPRESSIONTOKENS_H
