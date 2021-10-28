// Unit tests for LeetCode Solution 83
#include <gtest/gtest.h>
#include <string>
#include <tuple>
#include <vector>

#include "../src/83.cpp"
#include "./utils/list_util.hpp"

namespace {
class LeetCode83 : public testing::TestWithParam<
                       std::tuple<std::vector<int>, std::vector<int>>> {
protected:
  leetcode_83::Solution solution;
  LeetCode83() {}
  ~LeetCode83() override { freeListNodes(list); }
  void SetUp() override {
    std::vector<int> nodes;
    std::tie(nodes, expected) = GetParam();
    list = createList(nodes);
  }
  void TearDown() override {}
  ListNode *list;
  std::vector<int> expected;
};

// test_suite_name, test_name
TEST_P(LeetCode83, Test) {
  auto actual = solution.deleteDuplicates(list);
  auto actualVec = listToVector(actual);
  ASSERT_EQ(expected, actualVec);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(
    Pre, LeetCode83,
    testing::Values(std::make_tuple(std::vector<int>{1, 1, 2},
                                    std::vector<int>{1, 2}),
                    std::make_tuple(std::vector<int>{1, 1, 2, 3, 3},
                                    std::vector<int>{1, 2, 3})));
} // namespace