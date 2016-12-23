#pragma once

#include <string>
#include <vector>


class OsPath {
public:
  static std::string join(std::vector<std::string> names);
};
