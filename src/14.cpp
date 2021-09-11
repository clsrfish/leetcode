/**
 * 最长公共前缀
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace leetcode_0014 {
string key = "0014";
class Solution {
 public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) {
      return "";
    }
    string a = strs[0];
    for (size_t i = 1; i < strs.size(); i++) {
      string b = strs.at(i);
      a = commonPrefix(a, b);
    }
    return a;
  }

 private:
  string commonPrefix(string a, string b) {
    string lstr, sstr;
    if (a.length() > b.length()) {
      lstr = a;
      sstr = b;
    } else {
      lstr = b;
      sstr = a;
    }

    for (size_t i = 0; i < sstr.length(); i++) {
      if (sstr.at(i) != lstr.at(i)) {
        sstr = sstr.substr(0, i);
        break;
      }
    }
    return sstr;
  }
};

int main() {
  std::cout << key << ":最长公共前缀" << std::endl;
  vector<string> strs;
  strs.push_back("flower");
  strs.push_back("flow");
  strs.push_back("flight");
  vector<string> &ref = strs;
  cout << Solution().longestCommonPrefix(ref) << endl;
  return 0;
}

}  // namespace leetcode_0014