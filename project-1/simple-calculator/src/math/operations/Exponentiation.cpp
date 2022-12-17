//
// Created by adam on 12/17/22.
//

#include <complex>
#include "../../../include/math/operations/Exponentiation.h"

float Exponentiation::Evaluate() {
    return std::pow(val2, val1);
}

Exponentiation::Exponentiation(float val1, float val2) {
    this->val1 = val1;
    this->val2 = val2;
}