#include "Compiler.h"

#include "error.h"


int Compiler::compile(Build& build, Project& project) {
  // TODO: think about incremental build - reload only changed files,
  // tokenize and parse and analyze, then analyze depended code.
  // Think about diff detection, dependency organization (maybe store
  // separately).

  // loader
  // preprocessor
  // lexer
  // parser
  // analyzer
  // obj serializer
  // formatter

  return ERROR_OK;
}
