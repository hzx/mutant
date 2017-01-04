#include <iostream>

#include "App.h"
#include "error.h"


int main(int argc, const char *argv[]) {
  App app;

  // parse options before config, because config path can be overriden
  int error;

  error = app.initOptions(argc, argv);
  if (error < ERROR_OK) return error;

  error = app.initConfig();
  if (error < ERROR_OK) return error;

  return app.run();
}
