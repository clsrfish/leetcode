/**
 * 盛最多水的容器  
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace leetcode_0011
{
string key = "0011";
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        vector<int>::iterator head = height.begin();
        vector<int>::iterator tail = height.end();
        --tail;
        int w = height.size() - 1;
        int maxS = 0;
        while (head != tail)
        {
            int h = min(*head, *tail);
            int s = h * w;
            if (maxS < s)
            {
                maxS = s;
            }
            if (h == *head)
            {
                ++head;
            }
            else
            {
                --tail;
            }
            --w;
        }
        return maxS;
    }
};

int main()
{
    std::cout << key << ":盛最多水的容器" << std::endl;
    vector<int> height;
    height.push_back(1);
    height.push_back(8);
    height.push_back(6);
    height.push_back(2);
    height.push_back(5);
    height.push_back(4);
    height.push_back(8);
    height.push_back(3);
    height.push_back(7);
    vector<int> &ref = height;
    Solution solu;
    int s = solu.maxArea(ref);
    cout << "max area: " << s << endl;
    return 0;
}
} // namespace leetcode_0011