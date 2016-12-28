#pragma once

#include "Project.h"
#include "Build.h"
#include "Loader.h"
#include "Preprocessor.h"
#include "Lexer.h"
#include "Parser.h"
#include "Analyzer.h"
#include "ObjSerializer.h"
#include "Compiler.h"
#include "JsFormatter.h"
#include "JsStyleFormatter.h"
#include "CppFormatter.h"
#include "CppStyleFormatter.h"


class Compiler {
public:
  Loader loader;
  Preprocessor preprocessor;
  Lexer lexer;
  Parser parser;
  Analyzer analyzer;
  ObjSerializer serializer;
  JsFormatter jsFormatter;
  JsStyleFormatter jsStyleFormatter;
  CppFormatter cppFormatter;
  CppStyleFormatter cppStyleFormatter;

  int compile(Build& build, Project& project);
private:
};
