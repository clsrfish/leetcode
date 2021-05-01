/**
 * 寻找两个有序数组的中位数
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
namespace leetcode_0004 {
string key = "0004";
class Solution {
 public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int l = nums1.size() + nums2.size();
    bool d = l % 2 == 0;
    int mid = l / 2;
    int mids[2] = {0, 0};
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < nums1.size() && j < nums2.size() && k <= mid) {
      int a = nums1.at(i);
      int b = nums2.at(j);

      if (d && (k == mid - 1 || k == mid)) {
        mids[k == mid - 1 ? 0 : 1] = min(a, b);
      } else if (!d && k == mid) {
        mids[0] = min(a, b);
      }

      if (a <= b) {
        ++i;
      } else {
        ++j;
      }
      ++k;
    }

    while (k <= mid && i < nums1.size()) {
      if (d && (k == mid - 1 || k == mid)) {
        mids[k == mid - 1 ? 0 : 1] = nums1.at(i);
      } else if (!d && k == mid) {
        mids[0] = nums1.at(i);
      }
      ++i;
      ++k;
    }

    while (k <= mid && j < nums2.size()) {
      if (d && (k == mid - 1 || k == mid)) {
        mids[k == mid - 1 ? 0 : 1] = nums2.at(j);
      } else if (!d && k == mid) {
        mids[0] = nums2.at(j);
      }
      ++j;
      ++k;
    }

    return d ? (mids[0] + mids[1]) / 2.0f : mids[0];
  }
};
int main() {
  std::cout << key << ":寻找两个有序数组的中位数" << std::endl;
  vector<int> nums1;
  nums1.push_back(1);
  nums1.push_back(2);
  vector<int> nums2;
  nums2.push_back(3);
  nums2.push_back(4);
  vector<int> ref1 = nums1;
  vector<int> ref2 = nums2;
  cout << Solution().findMedianSortedArrays(ref1, ref2) << endl;

  return 0;
}
}  // namespace leetcode_0004