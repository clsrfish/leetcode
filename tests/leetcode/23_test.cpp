#include "../../src/leetcode/23.cpp"

#include <gtest/gtest.h>
#include "../utils/list_util.hpp"

namespace
{
  class LeetCode23 : public testing::TestWithParam<std::tuple<std::vector<std::vector<int>>, std::vector<int>>>
  {
  protected:
    leetcode_23::Solution solution;
    LeetCode23()
    {
    }
    ~LeetCode23() override
    {
    }
    void SetUp() override
    {
      std::vector<std::vector<int>> input;
      std::tie(input, expected) = GetParam();
      for (auto &&vec : input)
      {
        this->lists.push_back(createListNodesFromVec(vec));
      }
    }
    void TearDown() override
    {
    }

    std::vector<ListNode *> lists;
    std::vector<int> expected;
  };

  // test_suite_name, test_name
  TEST_P(LeetCode23, Test)
  {
    auto actual = solution.mergeKLists(this->lists);
    auto vec = listNodes2Vec(actual);
    ASSERT_EQ(expected, vec);
    freeListNodes(actual);
  }

  // prefix, test_suite_name
  INSTANTIATE_TEST_SUITE_P(
      leetcode, LeetCode23,
      testing::Values(
          std::make_tuple(std::vector<std::vector<int>>{{1, 4, 5}, {1, 3, 4}, {2, 6}, {}}, std::vector<int>{1, 1, 2, 3, 4, 4, 5, 6})));
}