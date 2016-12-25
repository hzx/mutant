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


TEST(OsPathTest, joinLeftRight) {
  std::string expected = "/www/foo/osd/ui";
  std::string actual = OsPath::join("/www/foo", "osd/ui");

  ASSERT_EQ(expected, actual);
}


TEST(OsPathTest, joinLeftSlashRight) {
  std::string expected = "/www/foo/osd/ui";
  std::string actual = OsPath::join("/www/foo/", "osd/ui");

  ASSERT_EQ(expected, actual);
}


TEST(OsPathTest, joinLeftEmptyRight) {
  std::string expected = "";
  std::string actual = OsPath::join("", "osd/ui");

  ASSERT_EQ(expected, actual);
}


TEST(OsPathTest, joinLeftRightEmpty) {
  std::string expected = "";
  std::string actual = OsPath::join("/www/foo", "");

  ASSERT_EQ(expected, actual);
}


TEST(OsPathTest, joinLeftEmptyRightEmpty) {
  std::string expected = "";
  std::string actual = OsPath::join("", "");

  ASSERT_EQ(expected, actual);
}


TEST(OsPathTest, existsFile) {
  std::string existedFile = "../../test_data/OsPath/file";

  ASSERT_TRUE(OsPath::exists(existedFile));
}


TEST(OsPathTest, existsDir) {
  std::string existedDir = "../../test_data/OsPath/dir";

  ASSERT_TRUE(OsPath::exists(existedDir));
}


TEST(OsPathTest, isDir) {
  std::string existedDir = "../../test_data/OsPath/dir";

  ASSERT_TRUE(OsPath::isDir(existedDir));
}


TEST(OsPathTest, isFile) {
  std::string existedFile = "../../test_data/OsPath/file";

  ASSERT_TRUE(OsPath::isFile(existedFile));
}


TEST(OsPathTest, ls) {
  std::string path = "../../test_data/OsPath/ls";

  std::vector<std::string> expected = { "dir1", "dir2", "file1.txt", "file2.txt" };
  std::vector<std::string> actual = OsPath::ls(path);

  ASSERT_EQ(expected, actual);
}
