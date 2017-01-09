#pragma once

#include <string>
#include <vector>
#include <functional>


class StringUtil {
public:
  static size_t find(std::string const& content, size_t begin, size_t end, std::function<bool (char)> predicate);
  // extract clean path from trailing spaces, ' and "
  static std::string extract(std::string const& content, size_t begin, size_t end);
  static std::vector<std::string> parseArgs(std::string const& content, size_t begin, size_t end);
  static std::vector<std::string> split(std::string const& content, char delimiter);
};
