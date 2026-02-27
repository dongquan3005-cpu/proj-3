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
