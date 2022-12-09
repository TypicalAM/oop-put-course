//
// Created by adam on 12/9/22.
//

#include <vector>
#include "OperatorToken.h"

#ifndef CLION_EXPRESSIONTOKENS_H
#define CLION_EXPRESSIONTOKENS_H


class ExpressionTokens {
private:
    std::vector<OperatorToken> supportedOps;
public:
    bool IsOperator(std::string &token);

    OperatorToken FromString(const std::string &token);

    ExpressionTokens();

    std::string AllSymbols();
};


#endif //CLION_EXPRESSIONTOKENS_H
