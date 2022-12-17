//
// Created by adam on 12/17/22.
//

#ifndef CLION_LOGICALAND_H
#define CLION_LOGICALAND_H


#include "../Operation.h"

class LogicalAND : public Operation {
private:
    float val1;
    float val2;
public:
    float Evaluate() override;

    LogicalAND(float val1, float val2);
};


#endif //CLION_LOGICALAND_H
