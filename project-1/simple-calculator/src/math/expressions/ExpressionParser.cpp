#include "../../../include/math/expressions/ExpressionParser.h"
#include "../../../include/math/expressions/ExpressionParseError.h"
#include "../../../include/math/expressions/ExpressionTokens.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>
#include <utility>
#include <valarray>

ExpressionParser ExpressionParser::RPN() {
  // Parse the tokens vector into an expression in Reverse Polish Notation
  std::stack<std::string> stack;
  std::vector<std::string> result;

  ExpressionTokens expr;

  for (std::string token : tokens) {
    if (expr.IsOperator(token)) {
      while (!stack.empty() && expr.IsOperator(stack.top())) {
        OperatorToken c0p = expr.FromString(token);
        OperatorToken c1p = expr.FromString(stack.top());
        if ((c0p.Association() == LEFT && c0p.Compare(c1p) <= 0) ||
            (c0p.Association() == RIGHT && c0p.Compare(c1p) < 0)) {
          result.push_back(stack.top());
          stack.pop();
          continue;
        }
        break;
      }
      stack.push(token);
    } else if ("(" == token) {
      stack.push(token);
    } else if (")" == token) {
      while (!stack.empty() && stack.top() != "(") {
        result.push_back(stack.top());
        stack.pop();
      }
      stack.pop();
    } else {
      result.push_back(token);
    }
  }

  while (!stack.empty()) {
    result.push_back(stack.top());
    stack.pop();
  }

  // Return the computed result
  return ExpressionParser(result);
}

ExpressionParser::ExpressionParser(const std::string &text) {
  // Set the text variable
  if (text.length() > 0 && text[0] == '-' && text[0] == '+') {
    this->text = std::string("0.0").append(text);
  } else {
    this->text = text;
  }

  // Split the text by mathematical symbols
  bool inDigit = true;
  std::string currentDigit;
  std::vector<std::string> newTokens;
  for (char c : this->text) {
    if (std::isdigit(c) || c == '.') {
      if (inDigit) {
        currentDigit.append(std::string(1, c));
      } else {
        currentDigit = std::string(1, c);
        inDigit = true;
      }
    } else {
      if (inDigit) {
        newTokens.push_back(currentDigit);
        newTokens.emplace_back(1, c);
        inDigit = false;
      } else {
        newTokens.emplace_back(1, c);
      }
    }
  }

  if (inDigit) {
    newTokens.push_back(currentDigit);
  }

  // Now add the new tokens, combining the letters like "O" and "R" into
  // operations
  for (auto token : newTokens) {
    if (token == "O")
      tokens.emplace_back("OR");
    else if (token == "R")
      continue;
    else if (token == "A")
      tokens.emplace_back("AND");
    else if (token == "N")
      continue;
    else if (token == "D")
      continue;
    else
      tokens.push_back(token);
  }
}

std::string ExpressionParser::Evaluate() {
  ExpressionTokens expr;
  std::string result;
  std::stack<float> stack;
  float value1, value2;

  for (auto token : tokens) {
    if (token.empty())
      continue;
    if (expr.IsOperator(token)) {
      if (stack.size() < 2)
        throw ExpressionParseError("invalid expression");
      value1 = stack.top();
      stack.pop();
      value2 = stack.top();
      stack.pop();
      stack.push(expr.PerformOperation(value1, value2, token));
    } else {
      try {
        stack.push(std::stof(token));
      } catch (std::invalid_argument err) {
        throw ExpressionParseError("invalid number");
      }
    }
  }

  // Display up to two decimal places
  std::stringstream stream;
  stream << std::fixed << std::setprecision(2) << stack.top();
  return stream.str();
}

ExpressionParser::ExpressionParser(std::vector<std::string> tokens) {
  this->tokens = std::move(tokens);
}
