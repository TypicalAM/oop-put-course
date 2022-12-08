//
// Created by adam on 12/8/22.
//

#include <string>
#include "../../../include/math/expressions/ExpressionTree.h"
#include "../../../include/math/expressions/ExpressionParseError.h"

ExpressionTree::ExpressionTree(const std::string &text) {
    // Parse the expression into an abstract syntax tree
    if (text.length() < 3) {
        throw ExpressionParseError("Length is less than three");
    }

    // Initialize the text field
    this->text = text;
}

std::string ExpressionTree::Evaluate() {
    // Traverse the tree and perform the operations
    return text.append("z");
}
