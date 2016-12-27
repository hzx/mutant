#include "Compiler.h"

#include "error.h"


int Compiler::compile(Build& build, Project& project) {
  // TODO: think about incremental build - reload only changed files,
  // tokenize and parse and analyze, then analyze depended code.
  // Think about diff detection, dependency organization (maybe store
  // separately).

  // loader
  // lexer
  // parser
  // analyzer
  // formatter

  return ERROR_OK;
}
