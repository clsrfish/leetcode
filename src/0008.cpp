/**
 * 字符串转换整数 (atoi)
 */
#include <iostream>
#include <map>
using namespace std;
namespace leetcode_0008 {
string key = "0008";
class Solution {
public:
  int myAtoi(string str) {
    int sign = 1;
    bool running = false;
    long result = 0;
    string::iterator iter = str.begin();
    while (iter != str.end()) {
      char c = (*iter);
      if (c == '-' || c == '+') {
        if (running) {
          return result;
        } else {
          running = true;
          sign = c == '-' ? -1 : 1;
        }
      } else if (c >= '0' && c <= '9') {
        running = true;
        result *= 10;
        result += sign * (c - '0');
        if (INT_MAX < result) {
          return INT_MAX;
        } else if (INT_MIN > result) {
          return INT_MIN;
        }
      } else {
        if (running) {
          return result;
        } else if (c != ' ') {
          return 0;
        }
      }
      ++iter;
    }
    return result;
  }
};
int main() {
  std::cout << key << ":字符串转换整数 (atoi)" << std::endl;
  map<string, int> inputs;
  inputs["42"] = 42;
  inputs["   -42"] = -42;
  inputs["4193 with words"] = 4193;
  inputs["words and 987"] = 0;
  inputs["-91283472332"] = -2147483648;
  inputs["2147483648"] = INT_MAX;
  auto iter = inputs.begin();
  while (iter != inputs.end()) {
    int result = Solution().myAtoi((*iter).first);
    cout << "string: " << (*iter).first << " result: " << result
         << " expected: " << (*iter).second << endl;
    ++iter;
  }
  return 0;
}
} // namespace leetcode_0008