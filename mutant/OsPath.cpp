#include "OsPath.h"

#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>

#include <sstream>
#include <fstream>
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
  return access(path.data(), F_OK) == 0;
}


bool OsPath::isFile(std::string const& path) {
  struct stat st;
  if (stat(path.data(), &st) != 0) return false; // error or not exists
  return (st.st_mode & S_IFREG) != 0; // is regular file
}


bool OsPath::isDir(std::string const& path) {
  struct stat st;
  if (stat(path.data(), &st) != 0) return false; // error or not exists
  return (st.st_mode & S_IFDIR) != 0; // is directory
}


std::vector<std::string> OsPath::ls(std::string const& path) {
  std::vector<std::string> names;

  DIR* dir = opendir(path.data());
  if (dir == nullptr) return names;

  struct dirent* cur;

  while ((cur = readdir(dir)) != nullptr) {
    names.push_back(cur->d_name);
  }

  closedir(dir);

  return names;
}
