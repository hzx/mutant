#pragma once

#include "Options.h"


class ArgParser {
public:
  int parse(Options& options, int argc, const char *argv[]);
  // extract clean path from trailing spaces, ' and "
  static std::string extractPath(std::string const& value, size_t begin, size_t end);
};
