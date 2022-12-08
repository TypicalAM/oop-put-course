//
// Created by adam on 12/6/22.
//

#ifndef CLION_ADDITION_H
#define CLION_ADDITION_H

#include "../Operation.h"

class Addition : public Operation {
private:
    float val1;
    float val2;
public:
    float Evaluate() override;

    Addition(float val1, float val2);
};

#endif //CLION_ADDITION_H
