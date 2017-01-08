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
