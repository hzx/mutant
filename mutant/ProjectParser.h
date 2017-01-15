#pragma once

#include <string>

#include "Project.h"


class ProjectParser {
public:
  int parse(Project& project, std::string const& content);
  int parseLine(Project& project, std::string const& content, size_t begin, size_t end);
};
