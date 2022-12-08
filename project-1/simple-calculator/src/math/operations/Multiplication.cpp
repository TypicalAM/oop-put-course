//
// Created by adam on 12/6/22.
//

#include "../../../include/math/operations/Multiplication.h"

float Multiplication::Evaluate() {
    return val1 * val2;
}

Multiplication::Multiplication(float val1, float val2) {
    this->val1 = val1;
    this->val2 = val2;
}
