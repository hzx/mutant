#pragma once

#include <string>
#include <vector>


class OsPath {
public:
  static std::string join(std::vector<std::string> const& names);
  static std::string join(std::string const& left, std::string const& right);
  static bool exists(std::string const& path);
};
