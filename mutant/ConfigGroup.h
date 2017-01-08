#pragma once

#include <string>
#include <vector>
#include <map>


class ConfigGroup {
public:
  std::string name;
  std::map<std::string, std::string> settings;
};
