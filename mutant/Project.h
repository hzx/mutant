#pragma once

#include <string>
#include <vector>
#include <map>


class Project {
public:
  std::string path;
  std::vector<std::string> repositories;
  std::map<std::string, std::string> targets;
};
