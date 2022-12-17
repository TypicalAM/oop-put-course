//
// Created by adam on 12/9/22.
//

#ifndef CLION_EXPRESSIONPARSER_H
#define CLION_EXPRESSIONPARSER_H


#include <string>
#include <vector>

class ExpressionParser {
private:
    std::string text;
    std::vector<std::string> tokens;
    explicit ExpressionParser(std::vector<std::string> tokens);
public:
    ExpressionParser RPN();

    std::string Evaluate();

    explicit ExpressionParser(const std::string &text);
};


#endif //CLION_EXPRESSIONPARSER_H
