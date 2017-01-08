#pragma once

#include <string>
#include <functional>


class StringUtil {
public:
  static size_t find(std::string const& content, size_t begin, size_t end, std::function<bool (char)> predicate);
  // extract clean path from trailing spaces, ' and "
  static std::string extract(std::string const& content, size_t begin, size_t end);
};
