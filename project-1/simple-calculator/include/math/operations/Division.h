//
// Created by adam on 12/17/22.
//

#ifndef CLION_DIVISION_H
#define CLION_DIVISION_H


#include "../Operation.h"

class Division : public Operation {
private:
    float val1;
    float val2;
public:
    float Evaluate() override;

    Division(float val1, float val2);
};


#endif //CLION_DIVISION_H
