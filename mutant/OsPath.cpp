#include "OsPath.h"

#include <sstream>
#include <algorithm>
#include <iterator>


std::string OsPath::join(std::vector<std::string> names) {
  if (names.empty()) return "";
  if (names.size() == 1) return names.front();

  std::ostringstream buf;

  std::copy(names.begin(), names.end() - 1, std::ostream_iterator<std::string>(buf, "/"));
  buf << names.back();

  return buf.str();
}
