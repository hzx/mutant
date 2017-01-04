#pragma once

#include <map>

#include "ConfigGroup.h"


class Config {
public:
  std::map<ConfigGroup> groups;
  ConfigGroup* core;
};
