//
// Created by adam on 12/8/22.
//

#ifndef CLION_EXPRESSIONTREE_H
#define CLION_EXPRESSIONTREE_H


class ExpressionTree {

public:
    explicit ExpressionTree(const std::string &);

    std::string Evaluate();

    std::string text;
};


#endif //CLION_EXPRESSIONTREE_H
