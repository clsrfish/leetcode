#include "../../src/leetcode/25.cpp"

#include <gtest/gtest.h>
#include "../utils/list_util.hpp"

namespace
{
  class LeetCode25 : public testing::TestWithParam<std::tuple<std::vector<int>, int, std::vector<int>>>
  {
  protected:
    leetcode_25::Solution solution;
    LeetCode25()
    {
    }
    ~LeetCode25() override
    {
    }
    void SetUp() override
    {
      std::vector<int> input;
      std::tie(input, this->k, this->expected) = GetParam();
      list = createListNodesFromVec(input);
    }
    void TearDown() override
    {
    }

    ListNode *list;
    int k;
    std::vector<int> expected;
  };

  // test_suite_name, test_name
  TEST_P(LeetCode25, Test)
  {
    auto actual = solution.reverseKGroup(this->list, this->k);
    auto vec = listNodes2Vec(actual);
    ASSERT_EQ(expected, vec);
    freeListNodes(actual);
  }

  // prefix, test_suite_name
  INSTANTIATE_TEST_SUITE_P(
      P, LeetCode25,
      testing::Values(
          std::make_tuple(std::vector<int>{1, 2, 3, 4, 5}, 3, std::vector<int>{3, 2, 1, 4, 5})));
}
