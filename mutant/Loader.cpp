#include "Loader.h"

#include "error.h"


int loadCodeModule(CodeModule& module, std::string const& path) {
  return ERROR_OK;
}


int loadStyleModule(StyleModule& module, std::string const& path) {
  return ERROR_OK;
}


std::string Loader::findModulePath(std::vector<std::string> const& names) {
  return "";
}


ModuleType Loader::detectModuleType(std::string const& path) {
  return ModuleType::NONE;
}
