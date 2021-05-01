/**
 *
 * 两数之和
 */
#include <iostream>
#include <map>
#include <vector>
using namespace std;

namespace leetcode_1 {
class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> result;
    map<int, int> bucket;

    for (int i = 0; i < nums.size(); i++) {
      int remain = target - nums.at(i);
      map<int, int>::iterator find = bucket.find(remain);
      if (find != bucket.end()) {
        result.push_back((*find).second);
        result.push_back(i);
        break;
      } else {
        bucket[nums.at(i)] = i;
      }
    }
    return result;
  }
};

}  // namespace leetcode_1