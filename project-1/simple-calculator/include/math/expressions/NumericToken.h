//
// Created by adam on 12/9/22.
//

#ifndef CLION_NUMERICTOKEN_H
#define CLION_NUMERICTOKEN_H


#include <string>

class NumericToken {
private:
    std::string symbol;
public:
    std::string Symbol();

    explicit NumericToken(std::string symbol);
};


#endif //CLION_NUMERICTOKEN_H
