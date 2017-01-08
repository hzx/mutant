#include <gmock/gmock.h>

#include <string>
#include <vector>

#include "mutant/IniParser.h"
#include "mutant/error.h"


class IniParserTest: public ::testing::Test {
public:
    Config config;
    IniParser parser;
};


TEST_F(IniParserTest, parse) {
  std::string content = R"(
[core]
user.email = test@example.com
path = /usr/local/lib/mutant/libs:$HOME/projects/mutant-libs
foo = "Some path with spaces here"

[watch]
bar = 12.3
)";

  int error = parser.parse(config, content);

  ASSERT_EQ(ERROR_OK, error);
  ASSERT_EQ(2, config.groups.size());

  auto it = config.groups.find("core");
  ASSERT_TRUE(it != config.groups.end());

  ConfigGroup& core = it->second;
  ASSERT_EQ(3, core.settings.size());

  auto emailIt = core.settings.find("user.email");
  ASSERT_TRUE(emailIt != core.settings.end());
  ASSERT_EQ("test@example.com", emailIt->second);

  auto pathIt = core.settings.find("path");
  ASSERT_TRUE(pathIt != core.settings.end());
  ASSERT_EQ("/usr/local/lib/mutant/libs:$HOME/projects/mutant-libs", pathIt->second);

  auto fooIt = core.settings.find("foo");
  ASSERT_TRUE(fooIt != core.settings.end());
  ASSERT_EQ("Some path with spaces here", fooIt->second);

  auto watchIt = config.groups.find("watch");
  ASSERT_TRUE(watchIt != config.groups.end());

  ConfigGroup& watch = watchIt->second;
  ASSERT_EQ(1, watch.settings.size());
}


TEST_F(IniParserTest, extractGroupName) {
  std::string content = " [some-group] ";
  std::string expected = "some-group";

  std::string name = IniParser::extractGroupName(content, 0, content.length());

  ASSERT_EQ(expected, name);
}
