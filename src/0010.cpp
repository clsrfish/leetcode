/**
 * 正则表达式匹配 
 */
#include <iostream>
#include <vector>
using namespace std;
namespace leetcode_0010
{
string key = "0010";
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        return false;
    }
};
int main()
{
    std::cout << key << ":正则表达式匹配" << std::endl;
    vector<string> s;
    vector<string> p;
    vector<bool> m;
    s.push_back("aa");
    p.push_back("a");
    m.push_back(false);

    s.push_back("aa");
    p.push_back("*a");
    m.push_back(true);

    s.push_back("ab");
    p.push_back(".*");
    m.push_back(true);

    s.push_back("aab");
    p.push_back("c*a*b*");
    m.push_back(true);

    s.push_back("mississippi");
    p.push_back("mis*is*p*.");
    m.push_back(false);

    for (int i = 0; i < s.size(); i++)
    {
        cout << (Solution().isMatch(s.at(i), p.at(i)) == m.at(i) ? "pass" : "falied") << endl;
    }
    return 0;
}
} // namespace leetcode_0010