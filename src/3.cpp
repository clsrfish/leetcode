/**
 * @file 3.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 无重复字符的最长子串
 * @version 0.1
 * @date 2021-05-01
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
namespace leetcode_3 {

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.length() <= 1) {
      return s.length();
    }
    map<char, int> marks;
    int start = 0;
    int max = 0;
    for (size_t i = 0; i < s.length(); i++) {
      char c = s.at(i);
      map<char, int>::iterator find = marks.find(c);
      if (find != marks.end() && (*find).second != -1)  // found repeated character
      {
        int tmp = i - start;
        max = max > tmp ? max : tmp;

        int last_index = (*find).second;
        // update marks
        for (auto begin = marks.begin(); begin != marks.end(); ++begin) {
          if (marks[(*begin).first] <= last_index) {
            marks[(*begin).first] = -1;
          }
        }
        marks[c] = i;

        // update start
        start = last_index + 1;
      } else {
        marks[c] = i;
      }
    }
    int tmp = s.length() - start;
    max = max > tmp ? max : tmp;
    return max;
  }
};
class Solution2 {
 public:
  int lengthOfLongestSubstring(string s) {
    size_t len = s.length();
    if (len <= 1) {
      return len;
    }
    int max = 1;
    int max_tmp = 1;
    size_t start_pos = 0;

    for (size_t i = 1; i < len; ++i) {
      const char c = s.at(i);
      size_t redundant_pos = s.rfind(c, i - 1);
      if (redundant_pos == string::npos || redundant_pos < start_pos) {  // no repeat
        ++max_tmp;
      } else if (redundant_pos >= start_pos) {  // repeat
        max = max > max_tmp ? max : max_tmp;
        start_pos = redundant_pos + 1;
        max_tmp = i - redundant_pos;
      }
    }
    return max >= max_tmp ? max : max_tmp;
  }
};

}  // namespace leetcode_3