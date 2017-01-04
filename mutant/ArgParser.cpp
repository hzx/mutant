#include "ArgParser.h"

#include <string>
#include <algorithm>

#include "error.h"


int ArgParser::parse(Options& options, int argc, const char *argv[]) {
  // skip first argument - executable name
  // if param contains equal sign - this is flag,
  // in other case - param
  std::for_each(argv + 1, argv + argc, [&options](std::string const& arg) {
    auto pos = arg.find('=');
    if (pos != std::string::npos) { // found key = value
      std::string key = pos == 0 ? "" : arg.substr(0, pos);
      std::string value = arg.substr(pos + 1, arg.size() - pos);
      options.flags.insert({ key, value });
    } else { // we have simple param
      options.params.push_back(arg);
    }
  });

  return ERROR_OK;
}


std::string ArgParser::extractPath(std::string const& value, size_t begin, size_t end) {
}
