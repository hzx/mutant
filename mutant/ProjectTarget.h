#pragma once

#include <string>
#include <vector>

#include "FormatterType.h"


class ProjectTarget {
public:
  std::string input;
  std::string output;
  std::vector<std::string> skip;
  FormatterType formatterType;
};
