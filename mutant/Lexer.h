#pragma once

#include <string>
#include <vector>

#include "Token.h"


class Lexer {
public:
  int tokenize(std::vector<Token>& tokens, std::string const& source);
};
