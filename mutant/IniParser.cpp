#include "IniParser.h"

#include <algorithm>

#include "error.h"
#include "StringUtil.h"


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

    error = parseLine(config, content, left, pos);
    if (isError(error)) return error;

    left = pos + 1;
  }

  return ERROR_OK;
}


int IniParser::parseLine(Config& config, std::string const& content, size_t begin, size_t end) {
  // find [ or =, this means group or value
  size_t pos = StringUtil::find(content, begin, end, [](char c) {
    return (c == '[' || c == '=');
  });
  if (pos == end) return ERROR_OK; // not found, skip this line

  // parse group
  if (content[pos] == '[') {
    size_t closeBracket = StringUtil::find(content, pos + 1, end, [](char c) {
      return c == ']';
    });
    if (closeBracket == end) return ERROR_INI_NO_CLOSE_BRACKET; // not found close bracket

    std::string name = content.substr(pos + 1, closeBracket - (pos + 1));

    ConfigGroup group { name = name };
    config.groups.insert({ name, group });

    // remember last create group
    this->group = &config.groups[name];
  } else { // parse value
    // find name
    std::string name = StringUtil::extract(content, begin, pos);

    // find value
    std::string value = StringUtil::extract(content, pos + 1, end);

    if (!name.empty()) { // value can be empty
      if (this->group == nullptr) return ERROR_INI_NO_GROUP_FOR_VALUE;

      this->group->settings.insert({ name, value });
    }
  }

  return ERROR_OK;
}
