#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "circvector.h"

using namespace std;
using namespace testing;

TEST(CircVectorCore, ConstructorEmpty) {
  CircVector<int> cv;
  EXPECT_TRUE(cv.empty());
  EXPECT_EQ(cv.size(), 0);
}

TEST(CircVectorCore, AtBasic) {
  CircVector<int> cv;
  cv.push_back(10);
  cv.push_back(20);

  EXPECT_EQ(cv.at(0), 10);
  EXPECT_EQ(cv.at(1), 20);
}

TEST(CircVectorCore, AtOutOfRangeThrows) {
  CircVector<int> cv;
  cv.push_back(1);
  EXPECT_THROW(cv.at(1), out_of_range);
}

TEST(CircVectorCore, PushBackBasic) {
  CircVector<int> cv;
  cv.push_back(1);
  cv.push_back(2);
  cv.push_back(3);

  EXPECT_EQ(cv.at(0), 1);
  EXPECT_EQ(cv.at(1), 2);
  EXPECT_EQ(cv.at(2), 3);
}

TEST(CircVectorCore, PushBackResize) {
  CircVector<int> cv(2);
  cv.push_back(1);
  cv.push_back(2);
  cv.push_back(3);  // forces resize

  EXPECT_EQ(cv.size(), 3);
  EXPECT_EQ(cv.at(0), 1);
  EXPECT_EQ(cv.at(1), 2);
  EXPECT_EQ(cv.at(2), 3);
}