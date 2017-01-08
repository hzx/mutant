#pragma once

#include <string>
#include <vector>
#include <map>

#include "ProjectTarget.h"


class Project {
public:
  std::string path;
  std::vector<std::string> repositories;
  std::vector<ProjectTarget> targets;
};
