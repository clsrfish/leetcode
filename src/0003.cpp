/**
 * 无重复字符的最长子串
 */
#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
namespace leetcode_0003 {
string key = "0003";
class Solution1 {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.length() <= 1) {
      return s.length();
    }
    map<char, int> marks;
    int start = 0;
    int max = 0;
    for (int i = 0; i < s.length(); i++) {
      char c = s.at(i);
      map<char, int>::iterator find = marks.find(c);
      if (find != marks.end() &&
          (*find).second != -1) // found repeated character
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
    int len = s.length();
    if (len <= 1) {
      return len;
    }
    int max = 1;
    int max_tmp = 1;
    int start_pos = 0;

    for (int i = 1; i < len; ++i) {
      const char c = s.at(i);
      int redundant_pos = s.rfind(c, i - 1);
      if (redundant_pos == string::npos ||
          redundant_pos < start_pos) { // no repeat
        ++max_tmp;
      } else if (redundant_pos >= start_pos) { // repeat
        max = max > max_tmp ? max : max_tmp;
        start_pos = redundant_pos + 1;
        max_tmp = i - redundant_pos;
      }
    }
    return max >= max_tmp ? max : max_tmp;
  }
};
int main() {
  std::cout << key << ":无重复字符的最长子串" << std::endl;
  vector<string> strs;
  // strs.push_back("abcabcbb");
  // strs.push_back("bbbbb");
  // strs.push_back("pwwkew");
  // strs.push_back("   ");
  strs.push_back("au");
  for (int i = 0; i < strs.size(); i++) {
    cout << Solution1().lengthOfLongestSubstring(strs.at(i)) << endl;
  }
  return 0;
}

} // namespace leetcode_0003