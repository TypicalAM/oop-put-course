#ifndef EXPRESSION_PARSER_H
#define EXPRESSION_PARSER_H

#include <string>
#include <vector>

class ExpressionParser {
private:
  std::string text;
  std::vector<std::string> tokens;
  explicit ExpressionParser(std::vector<std::string> tokens);

public:
  ExpressionParser RPN();
  std::string Evaluate();
  explicit ExpressionParser(const std::string &text);
};

#endif // EXPRESSION_PARSER_H
