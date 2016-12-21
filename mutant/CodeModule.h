#pragma once

#include <string>
#include <vector>

#include "BaseModule.h"
#include "nodes/Function.h"
#include "nodes/Class.h"


class CodeModule: public BaseModule {
public:
  std::vector<nodes::Function> functions;
  std::vector<nodes::Class> classes;
};
