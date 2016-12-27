#include <iostream>

#include "App.h"


int main(int argc, const char *argv[]) {
  App app;

  // parse options before config, because config path can be overriden
  app.initOptions(argc, argv);
  app.initConfig();

  return app.run();
}
