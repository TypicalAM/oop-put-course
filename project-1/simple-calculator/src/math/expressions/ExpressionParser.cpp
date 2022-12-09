//
// Created by adam on 12/9/22.
//

#include <stack>
#include "../../../include/math/expressions/ExpressionParser.h"
#include "../../../include/math/expressions/ExpressionTokens.h"

std::string ExpressionParser::RPN() {
    // Parse the tokens vector into an expression in Reverse Polish Notation
    std::stack<std::string> stack;
    std::string result;

    ExpressionTokens expr;

    for (std::string token:tokens) {
        if (expr.IsOperator(token)) {
            while (!stack.empty() && expr.IsOperator(stack.top())) {
                OperatorToken c0p = expr.FromString(token);
                OperatorToken c1p = expr.FromString(stack.top());
                if ((c0p.Association() == LEFT && c0p.Compare(c1p) <= 0) || (c0p.Association() == RIGHT && c0p.Compare(c1p) < 0)) {
                    result.append(stack.top());
                    stack.pop();
                    continue;
                }
                break;
            }
            stack.push(token);
        } else if ("(" == token) {
            stack.push(token);
        } else if (")" == token) {
            while (!stack.empty() && stack.top() != "(") {
                result.append(stack.top());
                stack.pop();
            }
            stack.pop();
        } else {
            result.append(token);
        }
    }

    while (!stack.empty()) {
        result.append(stack.top());
        stack.pop();
    }

    // Return the computed result
    return result;
}

ExpressionParser::ExpressionParser(const std::string& text) {
    // Parse the text into a tokens vector
    this->text = text;
    // TODO: Support floats and numbers instead of digits
    for (char c: text) tokens.emplace_back(1, c);
}
