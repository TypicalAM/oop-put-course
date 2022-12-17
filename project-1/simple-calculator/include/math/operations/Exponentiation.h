//
// Created by adam on 12/17/22.
//

#ifndef CLION_EXPONENTIATION_H
#define CLION_EXPONENTIATION_H


#include "../Operation.h"

class Exponentiation: public Operation{
private:
    float val1;
    float val2;
public:
    float Evaluate() override;

    Exponentiation(float val1, float val2);
};


#endif //CLION_EXPONENTIATION_H
