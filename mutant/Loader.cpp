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


std::string Loader::findModulePath(std::vector<std::string> const& names) {
  assert(project != nullptr);
  if (names.empty()) return "";

  std::string module = OsPath::join(names);

  std::find_if(project->repositories.begin(), project->repositories.end(),
    [&module](std::string const& repository) {
      std::string full = OsPath::join(repository, module);

      return !full.empty() && OsPath::exists(full);
    });

  return "";
}


ModuleType Loader::detectModuleType(std::string const& path) {
  return ModuleType::NONE;
}
