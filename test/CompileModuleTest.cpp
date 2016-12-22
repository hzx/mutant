#include <gmock/gmock.h>

#include "mutant/Compiler.h"


class CompileModuleTest: public ::testing::Test {
public:
  Compiler compiler;
};


TEST_F(CompileModuleTest, noImports) {
  FAIL();
}


TEST_F(CompileModuleTest, importCodeAndStyleModules) {
  FAIL();
}


TEST_F(CompileModuleTest, diamondDependency) {
  FAIL();
}
