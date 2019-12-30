/**
 * 罗马数字转整数 
 */
#include <iostream>
#include <string>
#include <map>
using namespace std;
namespace leetcode_0013
{
string key = "0013";
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
class Solution
{
public:
    int romanToInt(string s)
    {
        int cur = 1;
        int result = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            int v = char2int(s.at(i));
            if (cur <= v)
            {
                cur = v;
                result += v;
            }
            else
            {
                result -= v;
            }
        }
        return result;
    }

    int char2int(char c)
    {
        switch (c)
        {
        case 'M':
            return 1000;
        case 'D':
            return 500;
        case 'C':
            return 100;
        case 'L':
            return 50;
        case 'X':
            return 10;
        case 'V':
            return 5;
        case 'I':
            return 1;
        default:
            return 0;
        }
    }
};
int main()
{
    std::cout << key << ":罗马数字转整数" << std::endl;
    string romanNum = "MCMXCIV";
    cout << Solution().romanToInt(romanNum) << endl;
    return 0;
}

} // namespace leetcode_0013