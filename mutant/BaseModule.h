#pragma once

#include <string>

#include "ModuleType.h"
#include "File.h"
#include "Import.h"


class BaseModule {
public:
  ModuleType type = ModuleType::NONE;
  std::string name;
  std::string path;
  std::vector<File> files;
  std::vector<Import> imports;
};
