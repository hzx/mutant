#pragma once

#include <string>

#include "Config.h"
#include "IniParser.h"
#include "Options.h"
#include "ArgParser.h"
#include "Project.h"
#include "Build.h"
#include "Compiler.h"


std::string const DEFAULT_CONFIG_PATH = "/etc/mutant.conf";
std::string const CONFIG_FLAG = "config";


class App {
public:
  int run();
  int initOptions(int argc, const char *argv[]);
  int initConfig();
  int loadConfig(std::string& content);

  Config config;
  IniParser iniParser;
  Options options;
  ArgParser argParser;
  Project project;
  Build build;
  Compiler compiler;
};
