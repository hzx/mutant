#pragma once

#include "Options.h"


class ArgParser {
public:
  int parse(Options& options, int argc, const char *argv[]);
};
