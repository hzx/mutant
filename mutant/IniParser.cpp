#include "IniParser.h"

#include "error.h"


int IniParser::parse(Config& config, std::string const& content) {
  // reset current config group
  group = nullptr;

  size_t left = 0;
  size_t end = content.size();

  size_t pos;
  int error;

  // find the line positions and parseLine
  while (left < end) {
    pos = content.find('\n', left);

    // not found
    if (pos == std::string::npos) {
      // nothing to parse
      if (left >= end) return ERROR_OK;
      pos = end;
    }

    error = parseLine(content, left, pos);
    if (isError(error)) return error;

    left = pos + 1;
  }

  return ERROR_OK;
}


int IniParser::parseLine(Config& config, std::string const& content, size_t begin, size_t end) {

  return ERROR_NOT_IMPLEMENTED;
}


std::string IniParser::extractGroupName(std::string const& value, size_t begin, size_t end) {
  return "";
}
