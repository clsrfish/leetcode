/**
 * @file 0028.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 实现 strStr() https://leetcode-cn.com/problems/implement-strstr/
 * @version 0.1
 * @date 2021-04-29
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <string>

namespace leetcode_0028 {
std::string key = "0028";
class Solution {
 public:
  int strStr(std::string haystack, std::string needle) {
    int hLen = haystack.length(), nLen = needle.length();
    if (hLen < nLen) {
      return -1;
    } else if (nLen == 0) {
      return 0;
    }

    int i = 0, j = 0;
    while (i + nLen <= hLen) {
      for (j = 0; j < nLen; j++) {
        if (haystack.at(i + j) != needle.at(j)) {
          break;
        } else if (j == nLen - 1) {
          return i;
        }
      }
      i++;
    }

    return -1;
  }
};

int main() {
  std::cout << key << ": 实现 strStr" << std::endl;
  std::string haystack = "a", needle = "a";
  int index = Solution().strStr(haystack, needle);
  std::cout << index << std::endl;
  return 0;
}
}  // namespace leetcode_0028