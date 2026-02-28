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