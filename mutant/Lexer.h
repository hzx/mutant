#pragma once
#include <string>


class Lexer {
public:
  int tokenize(std::vector<Token>& tokens, std::string const& source);
};
