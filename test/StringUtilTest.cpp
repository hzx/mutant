#include <gmock/gmock.h>

#include <string>
#include <vector>

#include "mutant/StringUtil.h"


TEST(StringUtilTest, find) {
  std::string content = " a  ! ' \" ";

  size_t pos = StringUtil::find(content, 0, content.size(), [](char c) {
    return c == '!';
  });

  ASSERT_EQ(4, pos);

  pos = StringUtil::find(content, 0, content.size(), [](char c) {
    return c == 'b';
  });

  ASSERT_EQ(content.size(), pos);
}


TEST(StringUtilTest, extract) {
  std::string content = "  'foo/path here' ";
  std::string content2 = " \"Some value\"";

  std::string expected = "foo/path here";
  std::string expected2 = "Some value";

  std::string actual = StringUtil::extract(content, 0, content.size());
  std::string actual2 = StringUtil::extract(content2, 0, content2.size());

  ASSERT_EQ(expected, actual);
  ASSERT_EQ(expected2, actual2);
}


TEST(StringUtilTest, parseArgs) {
  std::string content = " -I foo/path ";
  std::vector<std::string> expected = {
    "-I", "foo/path"
  };

  std::vector<std::string> actual = StringUtil::parseArgs(content, 0, content.size());

  ASSERT_EQ(expected, actual);
}


TEST(StringUtilTest, split) {
  std::string content = "foo.bar.name";
  std::vector<std::string> expected = { "foo", "bar", "name" };

  std::vector<std::string> actual = StringUtil::split(content, '.');

  ASSERT_EQ(expected, actual);
}
