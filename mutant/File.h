#pragma once

#include <string>
#include <vector>

#include "Token.h"


class File {
public:
  std::string name;
  std::string path;
  std::string content;
  std::string hash;
  size_t size;
  std::vector<Token> tokens;
};
