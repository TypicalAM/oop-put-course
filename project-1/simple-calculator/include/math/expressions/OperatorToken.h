//
// Created by adam on 12/9/22.
//

#include <string>

#ifndef CLION_OPERATORTOKEN_H
#define CLION_OPERATORTOKEN_H

enum Associativity {
    LEFT, RIGHT
};

class OperatorToken {
    int precedence;
    std::string symbol;
    Associativity associativity;
public:
    int Compare(const OperatorToken &op) const;

    Associativity Association();

    std::string Symbol();

    OperatorToken(std::string symbol, Associativity associativity, int precedence);
};


#endif //CLION_OPERATORTOKEN_H
