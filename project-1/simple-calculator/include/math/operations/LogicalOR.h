//
// Created by adam on 12/17/22.
//

#ifndef CLION_LOGICALOR_H
#define CLION_LOGICALOR_H


#include "../Operation.h"

class LogicalOR : public Operation {
private:
    float val1;
    float val2;
public:
    float Evaluate() override;

    LogicalOR(float val1, float val2);
};


#endif //CLION_LOGICALOR_H
