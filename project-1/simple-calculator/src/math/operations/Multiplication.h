//
// Created by adam on 12/6/22.
//

#ifndef CLION_MULTIPLICATION_H
#define CLION_MULTIPLICATION_H


#include "../Operation.h"

class Multiplication : public Operation {
private:
    float val1;
    float val2;
public:
    float Evaluate() override;

    Multiplication(float val1, float val2);
};


#endif //CLION_MULTIPLICATION_H
