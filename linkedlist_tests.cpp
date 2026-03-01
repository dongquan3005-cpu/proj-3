#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "linkedlist.h"

using namespace std;
using namespace testing;

TEST(LinkedListCore, DefaultConstructorEmpty) {
  LinkedList<int> ll;
  EXPECT_TRUE(ll.empty());
  EXPECT_EQ(ll.size(), 0);
}

TEST(LinkedListCore, PushFrontBasic) {
  LinkedList<int> ll;

  ll.push_front(10);
  ll.push_front(20);

  EXPECT_EQ(ll.size(), 2);
  EXPECT_EQ(ll.at(0), 20);
  EXPECT_EQ(ll.at(1), 10);
}

TEST(LinkedListCore, PopFrontBasic) {
  LinkedList<int> ll;

  ll.push_front(1);
  ll.push_front(2);

  int val = ll.pop_front();

  EXPECT_EQ(val, 2);
  EXPECT_EQ(ll.size(), 1);
  EXPECT_EQ(ll.at(0), 1);
}

TEST(LinkedListCore, PopFrontEmptyThrows) {
  LinkedList<int> ll;
  EXPECT_THROW(ll.pop_front(), runtime_error);
}

TEST(LinkedListCore, PushBackBasic) {
  LinkedList<int> ll;
  ll.push_back(1);
  ll.push_back(2);

  EXPECT_EQ(ll.at(0), 1);
  EXPECT_EQ(ll.at(1), 2);
}

TEST(LinkedListCore, PushBackEmptyList) {
  LinkedList<int> ll;
  ll.push_back(5);

  EXPECT_EQ(ll.size(), 1);
  EXPECT_EQ(ll.at(0), 5);
}

TEST(LinkedListCore, PopBackSingleElement) {
  LinkedList<int> ll;
  ll.push_back(7);

  int val = ll.pop_back();
  EXPECT_EQ(val, 7);
  EXPECT_TRUE(ll.empty());
}

TEST(LinkedListCore, PopBackEmptyThrows) {
  LinkedList<int> ll;
  EXPECT_THROW(ll.pop_back(), runtime_error);
}

TEST(LinkedListCore, AtOutOfBoundsThrows) {
  LinkedList<int> ll;
  ll.push_back(1);

  EXPECT_THROW(ll.at(1), out_of_range);
}

TEST(LinkedListCore, ClearResetsList) {
  LinkedList<int> ll;
  ll.push_back(1);
  ll.push_back(2);

  ll.clear();

  EXPECT_TRUE(ll.empty());
  EXPECT_EQ(ll.size(), 0);
}

TEST(LinkedListAugmented, CopyConstructorBasic) {
  LinkedList<int> ll;
  ll.push_back(1);
  ll.push_back(2);
  ll.push_back(3);

  LinkedList<int> copy(ll);

  EXPECT_EQ(copy.size(), 3);
  EXPECT_EQ(copy.at(0), 1);
  EXPECT_EQ(copy.at(1), 2);
  EXPECT_EQ(copy.at(2), 3);
}

TEST(LinkedListAugmented, CopyConstructorEmpty) {
  LinkedList<int> ll;
  LinkedList<int> copy(ll);

  EXPECT_TRUE(copy.empty());
}

TEST(LinkedListAugmented, AssignmentBasic) {
  LinkedList<int> ll;
  ll.push_back(5);
  ll.push_back(6);

  LinkedList<int> other;
  other = ll;

  EXPECT_EQ(other.size(), 2);
  EXPECT_EQ(other.at(0), 5);
  EXPECT_EQ(other.at(1), 6);
}

TEST(LinkedListAugmented, SelfAssignment) {
  LinkedList<int> ll;
  ll.push_back(10);
  ll.push_back(20);

  LinkedList<int>& ref = ll;
  ll = ref;

  EXPECT_EQ(ll.size(), 2);
  EXPECT_EQ(ll.at(0), 10);
  EXPECT_EQ(ll.at(1), 20);
}

TEST(LinkedListAugmented, ToStringFormat) {
  LinkedList<int> ll;
  ll.push_back(1);
  ll.push_back(2);
  ll.push_back(3);

  EXPECT_EQ(ll.to_string(), "[1, 2, 3]");
}

TEST(LinkedListAugmented, FindBasic) {
  LinkedList<int> ll;
  ll.push_back(4);
  ll.push_back(5);
  ll.push_back(6);

  EXPECT_EQ(ll.find(5), 1);
}

TEST(LinkedListAugmented, FindNotFound) {
  LinkedList<int> ll;
  ll.push_back(4);

  EXPECT_EQ(ll.find(9), (size_t)-1);
}

TEST(LinkedListAugmented, RemoveLastBasic) {
  LinkedList<int> ll;
  ll.push_back(1);
  ll.push_back(2);
  ll.push_back(1);

  ll.remove_last(1);

  EXPECT_EQ(ll.to_string(), "[1, 2]");
}

TEST(LinkedListAugmented, RemoveLastThrows) {
  LinkedList<int> ll;
  ll.push_back(1);

  EXPECT_THROW(ll.remove_last(5), invalid_argument);
}

TEST(LinkedListExtras, InsertBeforeMiddle) {
  LinkedList<int> ll;
  ll.push_back(1);
  ll.push_back(3);

  ll.insert_before(1, 2);

  EXPECT_EQ(ll.to_string(), "[1, 2, 3]");
}

TEST(LinkedListExtras, InsertBeforeZero) {
  LinkedList<int> ll;
  ll.push_back(2);

  ll.insert_before(0, 1);

  EXPECT_EQ(ll.to_string(), "[1, 2]");
}

TEST(LinkedListExtras, InsertBeforeLastIndex) {
  LinkedList<int> ll;
  ll.push_back(1);
  ll.push_back(2);
  ll.push_back(4);

  ll.insert_before(2, 3);

  EXPECT_EQ(ll.to_string(), "[1, 2, 3, 4]");
}

TEST(LinkedListExtras, InsertBeforeOutOfRangeThrows) {
  LinkedList<int> ll;
  ll.push_back(1);

  EXPECT_THROW(ll.insert_before(2, 5), out_of_range);
}

TEST(LinkedListExtras, RemoveEveryOtherBasic) {
  LinkedList<int> ll;
  ll.push_back(0);
  ll.push_back(1);
  ll.push_back(2);
  ll.push_back(3);
  ll.push_back(4);

  ll.remove_every_other();

  EXPECT_EQ(ll.to_string(), "[0, 2, 4]");
}

TEST(LinkedListExtras, RemoveEveryOtherOddSize) {
  LinkedList<int> ll;
  ll.push_back(1);
  ll.push_back(2);
  ll.push_back(3);

  ll.remove_every_other();

  EXPECT_EQ(ll.to_string(), "[1, 3]");
}