#include "StringUtil.h"


size_t StringUtil::find(std::string const& content, size_t begin, size_t end, std::function<bool (char)> predicate) {
  for (size_t i = begin; i < end; ++i) {
    if (predicate(content[i])) return i;
  }

  return end; // not found position
}


std::string StringUtil::extract(std::string const& content, size_t begin, size_t end) {
  size_t left = begin;
  size_t right = end;

  char c;
  // find left position
  for (size_t i = left; i < end; ++i) {
    c = content[i];
    if (c != ' ' && c != '"' && c != '\'') {
      left = i;
      break;
    }
  }

  // find right position
  for (size_t i = end - 1; i > left; --i) {
    c = content[i];
    if (c != ' ' && c != '"' && c != '\'') {
      right = i + 1;
      break;
    }
  }

  return content.substr(left, right - left);
}


std::vector<std::string> StringUtil::parseArgs(std::string const& content, size_t begin, size_t end) {
  std::vector<std::string> args;

  size_t left = begin;
  size_t right;

  // left - find first non-space symbol
  // right - find first space symbol
  while (left < end) {
    left = StringUtil::find(content, left, end, [](char c) {
      return c != ' ';
    });

    right = StringUtil::find(content, left + 1, end, [](char c) {
      return c == ' ';
    });

    std::string arg = content.substr(left, right - left);
    if (!arg.empty()) args.push_back(arg);

    left = right; // move to the space
  }

  return args;
}
