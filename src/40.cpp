/**
 * @file 40.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief https://leetcode-cn.com/problems/combination-sum-ii/
 * @version 0.1
 * @date 2021-11-01
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace leetcode_40 {
class Solution {
public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates,
                                                int target) {
    std::sort(candidates.begin(), candidates.end());
    for (unsigned int i = 0; i < candidates.size(); i++) {
      counter[candidates[i]]++;
    }
    std::vector<std::vector<int>> res;
    std::vector<int> vals;
    combinationBacktrace(candidates, target, 0, res, vals);

    return res;
  }

private:
  std::map<int, unsigned int> counter;
  void combinationBacktrace(std::vector<int> &candidates, int target,
                            unsigned int index,
                            std::vector<std::vector<int>> &res,
                            std::vector<int> &vals) {
    if (target == 0) {
      res.emplace_back(vals);
      return;
    }
    unsigned int i, j, k;
    for (i = index; i < candidates.size();) {
      int valI = candidates[i];
      unsigned int countI = counter[valI];
      for (j = countI; j > 0; j--) {
        if (valI * j > target) {
          continue;
        }
        for (k = 0; k < j; k++) {
          vals.push_back(valI);
        }
        combinationBacktrace(candidates, target - valI * j, i + countI, res,
                             vals);
        for (k = 0; k < j; k++) {
          vals.pop_back();
        }
      }
      i += countI;
    }
  }
};
} // namespace leetcode_40
