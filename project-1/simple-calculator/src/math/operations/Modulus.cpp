//
// Created by adam on 12/17/22.
//

#include <cmath>
#include "../../../include/math/operations/Modulus.h"

float Modulus::Evaluate() {
    return  (int) std::round(val2) % (int) std::round(val1);
}

Modulus::Modulus(float val1, float val2) {
    this->val1 = val1;
    this->val2 = val2;
}