#pragma once

#include <vector>
#include <string>

#include "Project.h"
#include "CodeModule.h"
#include "StyleModule.h"


/**
 * Contains project modules, config, paths, state
 */
class Build {
public:
  std::string path;
  std::vector<BaseModule> modules;
};
