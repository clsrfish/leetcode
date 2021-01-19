/**
 * @file 0022.cpp
 * @author liuxin (clsrfish@gmail.com)
 * @brief 括号生成. https://leetcode-cn.com/problems/generate-parentheses/
 * @version 0.1
 * @date 2021-01-19
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <string>
#include <vector>

namespace leetcode_0022 {
std::string key = "0022";
class Solution {
private:
  static const char LEFT = '(';
  static const char RIGHT = ')';

  void generateDFS(std::vector<std::string> &res, char *parenthesis, int cur_index, int left_count, int right_count,
                   const unsigned int max_count) {
    if (left_count < right_count) {
      return;
    }
    if (cur_index == max_count) {
      if (left_count == right_count) {
        res.emplace_back(parenthesis);
      }
      return;
    }
    if (left_count < max_count / 2) {
      parenthesis[cur_index] = LEFT;
      generateDFS(res, parenthesis, cur_index + 1, left_count + 1, right_count, max_count);
    }

    if (left_count >= right_count) {
      parenthesis[cur_index] = RIGHT;
      generateDFS(res, parenthesis, cur_index + 1, left_count, right_count + 1, max_count);
    }
  }

public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> res;
    if (n > 0) {
      int buf_length = 2 * n + 1;
      char *parenthesis = new char[buf_length];
      parenthesis[buf_length - 1] = '\0';
      generateDFS(res, parenthesis, 0, 0, 0, buf_length - 1);
    }
    return res;
  }
};
int main() {
  std::cout << key << ": 括号生成" << std::endl;
  int n = 2;
  auto output = Solution().generateParenthesis(n);
  std::cout << "n: " << n << std::endl;
  return 0;
}
} // namespace leetcode_0022