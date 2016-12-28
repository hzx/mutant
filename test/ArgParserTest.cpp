#include <gmock/gmock.h>

#include <string>
#include <vector>

#include "mutant/ArgParser.h"
#include "mutant/error.h"


class ArgParserTest: public ::testing::Test {
public:
  Options options;
  ArgParser parser;
};


TEST_F(ArgParserTest, parse) {
  std::vector<char const*> argv = {
    "./app",
    "key=value",
    "-DVERSION=1.0.0.0",
    "-I/usr/local/lib/mutant/libs/",
    "-I../mutant-libs/",
    "~/.mutant.conf",
  };

  std::map<std::string, std::string> expectedFlags = {
    { "key", "value" },
    { "-DVERSION", "1.0.0.0" },
  };

  std::vector<std::string> expectedParams = {
    "-I/usr/local/lib/mutant/libs/",
    "-I../mutant-libs/",
    "~/.mutant.conf",
  };

  int error = parser.parse(options, argv.size(), argv.data());

  ASSERT_EQ(ERROR_OK, error);
  ASSERT_EQ(expectedFlags, options.flags);
  ASSERT_EQ(expectedParams, options.params);
}
