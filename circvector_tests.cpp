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

TEST(CircVectorCore, PushFrontBasic) {
  CircVector<int> cv;
  cv.push_front(1);
  cv.push_front(2);
  EXPECT_EQ(cv.size(), 2);
  EXPECT_EQ(cv.at(0), 2);
  EXPECT_EQ(cv.at(1), 1);
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
  cv.push_back(3);

  EXPECT_EQ(cv.size(), 3);
  EXPECT_EQ(cv.at(0), 1);
  EXPECT_EQ(cv.at(1), 2);
  EXPECT_EQ(cv.at(2), 3);
}

TEST(CircVectorCore, PushFrontWrapAround) {
  CircVector<int> cv(4);
  cv.push_back(1);
  cv.push_back(2);
  cv.push_back(3);
  cv.push_front(0);
  EXPECT_EQ(cv.at(0), 0);
  EXPECT_EQ(cv.at(1), 1);
  EXPECT_EQ(cv.at(2), 2);
  EXPECT_EQ(cv.at(3), 3);
}

TEST(CircVectorCore, PopFrontBasic) {
  CircVector<int> cv;
  cv.push_back(10);
  cv.push_back(20);
  int val = cv.pop_front();
  EXPECT_EQ(val, 10);
  EXPECT_EQ(cv.size(), 1);
  EXPECT_EQ(cv.at(0), 20);
}

TEST(CircVectorCore, PopBackBasic) {
  CircVector<int> cv;
  cv.push_back(5);
  cv.push_back(6);
  int val = cv.pop_back();
  EXPECT_EQ(val, 6);
  EXPECT_EQ(cv.size(), 1);
  EXPECT_EQ(cv.at(0), 5);
}

TEST(CircVectorCore, WrapAroundFront) {
  CircVector<int> cv(4);
  cv.push_back(1);
  cv.push_back(2);
  cv.push_back(3);
  cv.push_front(0);
  EXPECT_EQ(cv.at(0), 0);
  EXPECT_EQ(cv.at(1), 1);
  EXPECT_EQ(cv.at(2), 2);
  EXPECT_EQ(cv.at(3), 3);
}

TEST(CircVectorCore, WrapAroundBack) {
  CircVector<int> cv(4);
  cv.push_back(1);
  cv.push_back(2);
  cv.push_back(3);
  cv.push_back(4);
  cv.pop_front();
  cv.push_back(5);
  EXPECT_EQ(cv.at(0), 2);
  EXPECT_EQ(cv.at(3), 5);
}

TEST(CircVectorAugmented, CopyConstructorBasic) {
  CircVector<int> cv;
  cv.push_back(1);
  cv.push_back(2);
  cv.push_back(3);
  CircVector<int> copy(cv);
  EXPECT_EQ(copy.size(), 3);
  EXPECT_EQ(copy.at(0), 1);
  EXPECT_EQ(copy.at(1), 2);
  EXPECT_EQ(copy.at(2), 3);
}

TEST(CircVectorAugmented, AssignmentBasic) {
  CircVector<int> cv;
  cv.push_back(5);
  cv.push_back(6);
  CircVector<int> other;
  other = cv;
  EXPECT_EQ(other.size(), 2);
  EXPECT_EQ(other.at(0), 5);
  EXPECT_EQ(other.at(1), 6);
}

TEST(CircVectorAugmented, ToStringBasic) {
  CircVector<int> cv;
  cv.push_back(1);
  cv.push_back(2);
  cv.push_back(3);
  EXPECT_EQ(cv.to_string(), "[1, 2, 3]");
}

TEST(CircVectorAugmented, FindBasic) {
  CircVector<int> cv;
  cv.push_back(10);
  cv.push_back(20);
  cv.push_back(30);
  EXPECT_EQ(cv.find(20), 1);
}

TEST(CircVectorAugmented, FindNotFound) {
  CircVector<int> cv;
  cv.push_back(1);
  EXPECT_EQ(cv.find(99), (size_t)-1);
}

TEST(CircVectorExtras, RemoveLastBasic) {
  CircVector<int> cv;
  cv.push_back(1);
  cv.push_back(2);
  cv.push_back(1);
  cv.remove_last(1);
  EXPECT_EQ(cv.to_string(), "[1, 2]");
}

TEST(CircVectorExtras, InsertBeforeBasic) {
  CircVector<int> cv;
  cv.push_back(1);
  cv.push_back(3);
  cv.insert_before(1, 2);
  EXPECT_EQ(cv.to_string(), "[1, 2, 3]");
}

TEST(CircVectorExtras, RemoveEveryOtherBasic) {
  CircVector<int> cv;
  cv.push_back(0);
  cv.push_back(1);
  cv.push_back(2);
  cv.push_back(3);
  cv.push_back(4);
  cv.remove_every_other();
  EXPECT_EQ(cv.to_string(), "[0, 2, 4]");
}