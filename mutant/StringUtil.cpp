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


std::vector<std::string> StringUtil::split(std::string const& content, char delimiter) {
  std::vector<std::string> parts;

  size_t left = 0;
  size_t end = content.size();
  size_t delim;

  // find delimiter
  while (left < end) {
    delim = content.find(delimiter, left);
    if (delim == std::string::npos) { // not found
      delim = end;
    }

    std::string part = content.substr(left, delim - left);
    if (!part.empty()) parts.push_back(part);

    left = delim + 1;
  }

  return parts;
}


size_t StringUtil::startWithSkipSpaces(std::string const& content, size_t begin, size_t end, std::string const& with) {
  // find first non space symbol
  size_t nonSpace = StringUtil::find(content, begin, end, [](char c) {
    return c != ' ';
  });

  // non space symbols not found or not enough space in content to compare
  if (nonSpace == end || with.size() < end - nonSpace) return false;

  if (content.compare(nonSpace, with.size(), with) == 0) return nonSpace;

  return end;
}
