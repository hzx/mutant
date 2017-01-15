#include "ProjectParser.h"

#include <string>
#include <vector>
#include <algorithm>

#include "error.h"
#include "StringUtil.h"



int ProjectParser::parse(Project& project, std::string const& content) {
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

    error = parseLine(project, content, left, pos);
    if (isError(error)) return error;

    left = pos + 1;
  }

  return ERROR_OK;
}


// TODO(dem): use state pattern, split parsing
int ProjectParser::parseLine(Project& project, std::string const& content, size_t begin, size_t end) {
  std::vector<std::string> args = StringUtil::parseArgs(content, begin, end);
  if (args.empty()) return ERROR_OK;

  std::string& arg0 = args[0];

  size_t ipos = StringUtil::startWithSkipSpaces(arg0, 0, arg0.size(), "-I");
  // we have include path start with -I
  if (ipos != arg0.size()) {
    // it should contain path -I'/foo/path/here'
    std::string path = StringUtil::extract(arg0, ipos + 2, arg0.size());
    if (!path.empty()) {
      project.repositories.push_back(path);
    }

    return ERROR_OK;
  }

  size_t opos = StringUtil::startWithSkipSpaces(arg0, 0, arg0.size(), "-O");
  // we have output path start with -O
  if (opos != arg0.size()) {
    // it should contain path -O"../build/path/static/"
    std::string path = StringUtil::extract(arg0, opos + 2, arg0.size());
    if (!path.empty()) {
      project.outputPath = path;
    }

    return ERROR_OK;
  }

  // we have target line
  // input.module.name -o output -s skip.module.name

  return ERROR_NOT_IMPLEMENTED;
}
