#ifndef NUMERIC_TOKEN_H
#define NUMERIC_TOKEN_H

#include <string>

class NumericToken {
private:
  std::string symbol;

public:
  std::string Symbol();
  explicit NumericToken(std::string symbol);
};

#endif // NUMERIC_TOKEN_H
