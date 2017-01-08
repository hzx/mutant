#pragma once

#include <string>

#include "Config.h"


class IniParser {
public:
  int parse(Config& config, std::string const& content);
  int parseLine(Config& config, std::string const& content, size_t begin, size_t end);
  // current group
  ConfigGroup* group = nullptr;
};
