#include "Loader.h"

#include <cassert>

#include <algorithm>

#include "error.h"
#include "OsPath.h"


int loadCodeModule(CodeModule& module, std::string const& path) {

  return ERROR_OK;
}


int loadStyleModule(StyleModule& module, std::string const& path) {
  return ERROR_OK;
}


std::vector<std::string>&& Loader::findModulePaths(std::vector<std::string> const& names) {
  assert(project != nullptr);

  std::vector<std::string> paths;

  if (names.empty()) return std::move(paths);

  std::string module = OsPath::join(names);

  std::for_each(project->repositories.begin(), project->repositories.end(),
    [&paths, &module](std::string const& repository) {
      std::string full = OsPath::join(repository, module);

      if (!full.empty() && OsPath::exists(full)) paths.push_back(full);
    });

  return std::move(paths);
}


ModuleType Loader::detectModuleType(std::string const& path) {
  return ModuleType::NONE;
}
