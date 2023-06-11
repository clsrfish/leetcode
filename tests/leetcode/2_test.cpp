// Unit tests for LeetCode Solution 2

#include "../../src/leetcode/2.cpp"

#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

#include "../utils/list_util.hpp"

namespace {

class LeetCode2 : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>, std::vector<int>>> {
 protected:
  leetcode_2::Solution solution;
  LeetCode2() {
  }
  ~LeetCode2() override {
  }
  void SetUp() override {
    std::vector<int> v1, v2;
    std::tie(v1, v2, expected) = GetParam();

    l1 = createListNodesFromVec(v1);
    l2 = createListNodesFromVec(v2);
  }
  void TearDown() override {
    freeListNodes(l1);
    freeListNodes(l2);
  }

  ListNode* l1 = nullptr;
  ListNode* l2 = nullptr;
  std::vector<int> expected;
};

// test_suite_name, test_name
TEST_P(LeetCode2, Test) {
  auto actual = solution.addTwoNumbers(l1, l2);

  ASSERT_EQ(listNodes2Vec(actual), expected);

  freeListNodes(actual);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(P, LeetCode2,
                         testing::Values(std::make_tuple(std::vector<int>({2, 4, 3}), std::vector<int>({5, 6, 4}),
                                                         std::vector<int>({7, 0, 8}))));

}  // namespace