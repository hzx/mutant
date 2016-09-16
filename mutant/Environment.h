#pragma once

#include <string>
#include <unordered_map>


class Environment {
public:
private:
  std::unordered_map<std::string, std::string> vars;
};
