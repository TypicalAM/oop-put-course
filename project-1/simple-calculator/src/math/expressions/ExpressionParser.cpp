//
// Created by adam on 12/9/22.
//

#include <cmath>
#include <stack>
#include <iostream>
#include <utility>
#include <valarray>
#include "../../../include/math/expressions/ExpressionParser.h"
#include "../../../include/math/expressions/ExpressionTokens.h"
#include "../../../include/math/expressions/ExpressionParseError.h"

ExpressionParser ExpressionParser::RPN() {
    // Parse the tokens vector into an expression in Reverse Polish Notation
    std::stack<std::string> stack;
    std::vector<std::string> result;

    ExpressionTokens expr;

    for (std::string token: tokens) {
        if (expr.IsOperator(token)) {
            while (!stack.empty() && expr.IsOperator(stack.top())) {
                OperatorToken c0p = expr.FromString(token);
                OperatorToken c1p = expr.FromString(stack.top());
                if ((c0p.Association() == LEFT && c0p.Compare(c1p) <= 0) ||
                    (c0p.Association() == RIGHT && c0p.Compare(c1p) < 0)) {
                    result.push_back(stack.top());
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
                result.push_back(stack.top());
                stack.pop();
            }
            stack.pop();
        } else {
            result.push_back(token);
        }
    }

    while (!stack.empty()) {
        result.push_back(stack.top());
        stack.pop();
    }

    // Return the computed result
    return ExpressionParser(result);
}

ExpressionParser::ExpressionParser(const std::string &text) {
    // Set the text variable
    this->text = text;

    // Split the text by mathematical symbols
    bool inDigit = true;
    std::string currentDigit;
    for (char c:text) {
        if (std::isdigit(c) || c=='.') {
            if (inDigit) {
                currentDigit.append(std::string(1,c));
            } else {
                currentDigit = std::string(1,c);
                inDigit = true;
            }
        } else {
            if (inDigit) {
                tokens.push_back(currentDigit);
                tokens.emplace_back(1, c);
                inDigit = false;
            } else {
                tokens.emplace_back(1, c);
            }
        }
    }

    if (inDigit) {
        tokens.push_back(currentDigit);
    }
}

std::string ExpressionParser::Evaluate() {
    // Take the tokenized expression and calculate it
    ExpressionTokens expr;
    std::string result;
    float a,b;
    printf("test\n");
    printf("%zu\n", tokens.size());
    std::stack<float> stk;
    for (auto token:tokens) {
        if (token.empty()) continue;
        printf("Calculating for %s\n", token.c_str());
        if (expr.IsOperator(token)) {
            a = stk.top();
            stk.pop();
            b = stk.top();
            stk.pop();
            if (token=="+") {
                stk.push(a+b);
            } else if (token=="^") {
                stk.push(std::pow(b,a));
            } else if (token=="*") {
                stk.push(a*b);
            }
        } else {
            printf("Pushign to the stack\n");
            try {
                stk.push(std::stof(token));
            } catch (std::invalid_argument err) {
                throw ExpressionParseError("invalid number");
            }
        }
    }

    return std::to_string(std::floor(stk.top()*100.0)/100.0);
}

ExpressionParser::ExpressionParser(std::vector<std::string> tokens) {
    this->tokens = std::move(tokens);
}
