//
// Created by adam on 12/17/22.
//

#ifndef CLION_MODULUS_H
#define CLION_MODULUS_H


#include "../Operation.h"

class Modulus : public Operation {
private:
    float val1;
    float val2;
public:
    float Evaluate() override;

    Modulus(float val1, float val2);
};


#endif //CLION_MODULUS_H
