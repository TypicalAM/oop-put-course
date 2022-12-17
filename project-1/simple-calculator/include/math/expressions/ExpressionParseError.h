#ifndef EXPRESSION_PARSE_ERROR_H
#define EXPRESSION_PARSE_ERROR_H

#include <exception>
#include <string>

class ExpressionParseError : public std::exception {
private:
  char *message;

public:
  char *what();
  explicit ExpressionParseError(char *msg);
};

#endif // EXPRESSION_PARSE_ERROR_H
