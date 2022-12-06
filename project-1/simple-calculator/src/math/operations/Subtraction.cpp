//
// Created by adam on 12/6/22.
//

#include "Subtraction.h"

float Subtraction::evaluate() {
    return val1 - val2;
}

Subtraction::Subtraction(float val1, float val2) {
    this->val1 = val1;
    this->val2 = val2;
}
