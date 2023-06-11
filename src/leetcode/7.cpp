/**
 * 整数反转
 */
#include <iostream>
#include <map>
using namespace std;
namespace leetcode_0007 {

string key = "0007";
class Solution {
public:
  int reverse(int x) {
    long result = 0;
    int multi = x > 0 ? 1 : -1;
    string s = to_string(x > 0 ? x : -x);
    int l = s.length();
    long m[] = {1,       10,       100,       1000,       10000,      100000,
                1000000, 10000000, 100000000, 1000000000, 10000000000};
    for (int i = l - 1; i >= 0; --i) {
      int v = s.at(i) - '0';
      if (v != 0) {
        result += v * m[i];
      }
    }
    result *= multi;
    return (result > 2147483647 || result < -2147483648) ? 0 : result;
  }
};
class SolutionReverseInteger2 {
public:
  int solution(int x) {
    long result = 0;
    int multi = x > 0 ? 1 : -1;
    x *= multi;
    while (x > 0) {
      result *= 10;
      result += x % 10;
      x /= 10;
    }

    result *= multi;
    return (result > 2147483647 || result < -2147483648) ? 0 : result;
  }
};
int main() {
  std::cout << key << ":整数反转" << std::endl;
  map<int, int> inputs;
  // inputs[123] = 321;
  // inputs[-123] = -321;
  // inputs[120] = 21;
  inputs[1534236469] = 0;
  // 1056389759
  // 2147483647
  for (auto iter = inputs.begin(); iter != inputs.end(); ++iter) {
    cout << (Solution().reverse((*iter).first) == (*iter).second ? "true"
                                                                 : "false")
         << endl;
  }

  return 0;
}
} // namespace leetcode_0007