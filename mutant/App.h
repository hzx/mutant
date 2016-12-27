#pragma once

#include "Config.h"
#include "IniParser.h"
#include "Options.h"
#include "ArgParser.h"
#include "Project.h"
#include "Build.h"
#include "Compiler.h"


class App {
public:
  int run();
  int initOptions(int argc, const char *argv[]);
  int initConfig();

  Config config;
  IniParser iniParser;
  Options options;
  ArgParser argParser;
  Project project;
  Build build;
  Compiler compiler;
};
