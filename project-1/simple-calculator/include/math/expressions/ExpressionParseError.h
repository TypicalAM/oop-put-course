//
// Created by adam on 12/8/22.
//

#ifndef CLION_EXPRESSIONPARSEERROR_H
#define CLION_EXPRESSIONPARSEERROR_H


#include <exception>
#include <string>

class ExpressionParseError : public std::exception {
private:
    char *message;
public:
    char *what();

    explicit ExpressionParseError(char *msg);
};

#endif //CLION_EXPRESSIONPARSEERROR_H
