/**
 * 最长回文子串
 */
#include <iostream>
#include <string>
#include <vector>
// #include <algorithm>
using namespace std;
namespace leetcode_0005 {
string key = "0005";
class Solution {
 public:
  string longestPalindrome(string s) {
    size_t length = s.length();
    string result = "";
    for (size_t i = 0; i < length; i++) {
      // single
      size_t max_target_step = min(i, length - 1 - i);

      longestIntermediatePalindrome(s, length, &result, max_target_step, i, i);

      // double
      if (i + 1 == length) {
        return result;
      }
      max_target_step = min(i, length - 1 - (i + 1));
      longestIntermediatePalindrome(s, length, &result, max_target_step, i, i + 1);
    }
    return result;
  }

 private:
  void longestIntermediatePalindrome(string s, int length, string *result, unsigned int max_target_step, unsigned int m,
                                     unsigned int n) {
    unsigned int max_length = max_target_step * 2 + n - m + 1;
    if ((*result).length() > max_length) {
      return;
    }
    unsigned int step = 0;
    while (step <= max_target_step) {
      if (s.at(m - step) != s.at(n + step)) {
        unsigned int tmp = (step - 1) * 2 + n - m + 1;
        if (tmp > (*result).length()) {
          *result = s.substr(m - step + 1, tmp);
        }
        return;
      }
      ++step;
    }
    *result = s.substr(m - max_target_step, max_length);
  }
};

int main() {
  std::cout << key << ":最长回文子串" << std::endl;
  vector<string> strs;
  strs.push_back("babad");
  strs.push_back("cbbd");
  strs.push_back("a");
  for (size_t i = 0; i < strs.size(); i++) {
    cout << Solution().longestPalindrome(strs.at(i)) << endl;
  }
  return 0;
}
}  // namespace leetcode_0005