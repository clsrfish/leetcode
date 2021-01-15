/**
 * Z 字形变换
 */
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
namespace leetcode_0006 {
string key = "0006";
class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows <= 1) {
      return s;
    }

    int length = s.length();
    string result = "";
    for (int r = 0; r < numRows; r++) {
      int c = 0;
      while (true) {
        int index = (c / 2 * (2 * numRows - 2)) +
                    ((c + 1) % 2 == 0 ? (2 * numRows - r - 1) : (r + 1));
        int indexTmp = 0;
        if (index > length) {
          break;
        } else {
          result += s.at(index - 1);
        }
        c += (r == 0 || r == numRows - 1) ? 2 : 1;
      }
    }
    return result;
  }
};
int main() {
  std::cout << key << ":Z 字形变换" << std::endl;
  string input = "PAYPALISHIRING";
  map<int, string> table;
  // table[3] = "PAHNAPLSIIGYIR";
  // table[4] = "PINALSIGYAHRPI";
  input = "A";
  table[1] = "A";
  auto iter = table.begin();

  while (iter != table.end()) {
    cout << Solution().convert(input, (*iter).first).compare((*iter).second)
         << endl;
    ++iter;
  }
  return 0;
}
} // namespace leetcode_0006