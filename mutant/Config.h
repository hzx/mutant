#pragma once

#include <string>
#include <map>

#include "ConfigGroup.h"


class Config {
public:
  std::map<std::string, ConfigGroup> groups;
  ConfigGroup* core;
};
