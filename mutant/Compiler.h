#pragma once

#include "Project.h"
#include "Build.h"
#include "Loader.h"
#include "Lexer.h"
#include "Parser.h"
#include "Analyzer.h"


class Compiler {
public:
  Loader loader;
  Lexer lexer;
  Parser parser;
  Analyzer analyzer;
private:
};
