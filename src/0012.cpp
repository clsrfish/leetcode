/**
 * 整数转罗马数字
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace leetcode_0012 {
string key = "0012";
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
class Solution {
   public:
    string intToRoman(int num) {
        // 1000
        string result = convert(1000, num, 'M', 'D', 'C');
        num = num % 1000;
        // 100
        result += convert(100, num, 'M', 'D', 'C');
        num = num % 100;
        // 10
        result += convert(10, num, 'C', 'L', 'X');
        num = num % 10;
        // 1
        result += convert(1, num, 'X', 'V', 'I');
        return result;
    }

   private:
    string convert(int threshold, int num, char up, char mid, char low) {
        string result = "";
        int c = num / threshold;
        if (threshold == 1000) {
            result.append(string(c, up));
        } else {
            if (c == 9) {
                result = result + low + up;
            } else if (c <= 3) {
                result.append(string(c, low));
            } else if (c >= 5) {
                result += mid;
                result.append(string(c - 5, low));
            } else {
                result.append(string(5 - c, low));
                result += mid;
            }
        }
        return result;
    }
};
int main() {
    std::cout << key << ":整数转罗马数字" << std::endl;
    int num = 1994;
    Solution solution;
    string romanNum = solution.intToRoman(num);
    cout << romanNum << endl;
    return 0;
}

}  // namespace leetcode_0012