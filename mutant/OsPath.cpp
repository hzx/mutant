#include "OsPath.h"

#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>

#include <sstream>
#include <algorithm>
#include <iterator>


std::string OsPath::join(std::vector<std::string> const& names) {
  if (names.empty()) return "";
  if (names.size() == 1) return names.front();

  std::ostringstream buf;

  std::copy(names.begin(), names.end() - 1,
    std::ostream_iterator<std::string>(buf, "/"));
  buf << names.back();

  return buf.str();
}


std::string OsPath::join(std::string const& left, std::string const& right) {
  // make join safe, if left or right is empty it will
  // produce very dangerous path
  if (left.empty() || right.empty()) return "";

  std::ostringstream buf;

  buf << left;
  if (left.back() != '/') buf << '/';
  buf << right;

  return buf.str();
}


bool OsPath::exists(std::string const& path) {
  DIR* dir = opendir(path.c_str());
  bool exists = dir != nullptr;
  if (dir) closedir(dir);
  return exists;
}
