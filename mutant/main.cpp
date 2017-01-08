#include <iostream>

#include "App.h"
#include "error.h"


int main(int argc, const char *argv[]) {
  App app;

  // parse options before config, because config path can be overriden
  int error;

  error = app.initOptions(argc, argv);
  if (isError(error)) return error;

  error = app.initConfig();
  if (isError(error)) return error;

  return app.run();
}
