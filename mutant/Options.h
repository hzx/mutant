#pragma once

#include <map>
#include <string>
#include <vector>


class Options {
public:
  std::map<std::string, std::string> flags;
  std::vector<std::string> params;
};
