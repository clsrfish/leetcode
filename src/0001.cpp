/**
 *
 * 两数之和
 */
#include <iostream>
#include <map>
#include <vector>
using namespace std;

namespace leetcode_0001 {
string key = "0001";
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
int main() {
    std::cout << key << ":两数之和" << std::endl;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    int target = 9;
    vector<int> &ref = nums;
    auto result = Solution().twoSum(ref, target);
    cout << result.at(0) << " " << result.at(1) << endl;
    return 0;
}

}  // namespace leetcode_0001