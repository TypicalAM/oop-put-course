//
// Created by adam on 12/8/22.
//

#ifndef CLION_EXPRESSIONPARSEERROR_H
#define CLION_EXPRESSIONPARSEERROR_H

#include "exception"
#include "string"

class ExpressionParseError : public std::exception {
private:
    char *message;
public:
    explicit ExpressionParseError(char *msg) : message(msg) {}

    char *what() { return message; }
};

#endif //CLION_EXPRESSIONPARSEERROR_H
