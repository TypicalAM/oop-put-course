//
// Created by adam on 12/9/22.
//

#include "../../../include/math/expressions/ExpressionTokens.h"
#include "../../../include/math/expressions/ExpressionParseError.h"

bool ExpressionTokens::IsOperator(std::string &token) {
    for (OperatorToken op:supportedOps) if (token == op.Symbol()) return true;
    return false;
}

OperatorToken ExpressionTokens::FromString(const std::string& token) {
    for (OperatorToken op:supportedOps) {
        if (token== op.Symbol()) {
            return op;
        }
    }
    throw ExpressionParseError("operators vector too narrow");
}

ExpressionTokens::ExpressionTokens() {
    supportedOps.emplace_back("+", LEFT, 0);
    supportedOps.emplace_back("-", LEFT, 0);
    supportedOps.emplace_back("/", LEFT, 5);
    supportedOps.emplace_back("*", LEFT, 5);
    supportedOps.emplace_back("%", LEFT, 5);
    supportedOps.emplace_back("^", RIGHT, 10);
}
