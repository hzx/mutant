#pragma once
#include <string>


class Token {
public:
  std::string word;
  size_t line;
  size_t pos;
};
