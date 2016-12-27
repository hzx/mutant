#pragma once

#include "Project.h"
#include "Build.h"
#include "Loader.h"
#include "Lexer.h"
#include "Parser.h"
#include "Analyzer.h"
#include "JsFormatter.h"
#include "CppFormatter.h"


class Compiler {
public:
  Loader loader;
  Lexer lexer;
  Parser parser;
  Analyzer analyzer;
  ObjSerializer serializer;
  JsFormatter jsFormatter;
  CppFormatter cppFormatter;

  int compile(Build& build, Project& project);
private:
};
