#include <gmock/gmock.h>

#include <string>
#include <vector>

#include "mutant/OsPath.h"


TEST(OsPathTest, joinEmpty) {
  std::vector<std::string> names;
  std::string expected;

  std::string actual = OsPath::join(names);

  ASSERT_EQ(expected, actual);
}


TEST(OsPathTest, joinOne) {
  std::vector<std::string> names = {"hello"};
  std::string expected = "hello";

  std::string actual = OsPath::join(names);

  ASSERT_EQ(expected, actual);
}


TEST(OsPathTest, joinTwo) {
  std::vector<std::string> names = {"hello", "world"};
  std::string expected = "hello/world";

  std::string actual = OsPath::join(names);

  ASSERT_EQ(expected, actual);
}
