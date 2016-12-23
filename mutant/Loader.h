#pragma once

#include <string>
#include <vector>

#include "Project.h"
#include "ModuleType.h"
#include "CodeModule.h"
#include "StyleModule.h"


class Loader {
public:
  // load module files, return error
  int loadCodeModule(CodeModule& module, std::string const& path);
  int loadStyleModule(StyleModule& module, std::string const& path);
  // return module path
  // names - absolute module name
  std::string findModulePath(std::vector<std::string> const& names);
  // detect module type by searching files in path with filtered extensions,
  // *.mut - for CODE module
  // *.mus - for STYLE module
  // mixed files inside of one path is forbidden
  ModuleType detectModuleType(std::string const& path);

  Project* project = nullptr;
};
