#pragma once

#include "Project.h"
#include "Build.h"
#include "Compiler.h"


class App {
public:
  int run();

  Project project;
  Build build;
  Compiler compiler;
};
