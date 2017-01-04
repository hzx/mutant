#include "App.h"

#include "error.h"
#include "OsPath.h"


int App::run() {
  // TODO:
  // put merged repositories to the project from config, options; and more
  // (repositories from options have more priority - put in the beginning)
  // create/init project
  // create/init build
  // compile

  // TODO:
  // make watch mode from command line options,
  // incremental build.

  return ERROR_OK;
}


int App::initOptions(int argc, const char *argv[]) {
  return argParser.parse(options, argc, argv);
}


int App::initConfig() {
  std::string content;
  int error = loadConfig(content);
  if (error < ERROR_OK) return error;

  return iniParser(config, content);
}


int App::loadConfig(std::string& content) {
  // take DEFAULT_CONFIG_PATH or overriden from options
  auto search = options.flags.find(CONFIG_FLAG);
  std::string path = search != options.flags.end() ?
    search->second : DEFAULT_CONFIG_PATH;

  if (!OsPath::exists(path) || !OsPath::isFile(path))
    return APP_CONFIG_NOT_EXISTS;

  content = OsPath::load(path);
  return ERROR_OK;
}
