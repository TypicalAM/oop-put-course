//
// Created by adam on 12/6/22.
//

#ifndef CLION_SUBTRACTION_H
#define CLION_SUBTRACTION_H


#include "../Operation.h"

class Subtraction : public Operation {
private:
    float val1;
    float val2;
public:
    float evaluate() override;

    Subtraction(float val1, float val2);
};


#endif //CLION_SUBTRACTION_H
