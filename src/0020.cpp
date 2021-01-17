/**
 * @file 0020.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 有效的括号. https://leetcode-cn.com/problems/valid-parentheses/
 * @version 0.1
 * @date 2021-01-16
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

namespace leetcode_0020 {
std::string key = "0020";
class Solution {
public:
  bool isValid(const std::string &s) {
    if (s.length() == 0 || s.length() % 2 == 1) {
      return false;
    }

    std::stack<char> brackets;

    for (size_t i = 0; i < s.length(); i++) {
      auto c = s.at(i);
      if (c == '(' || c == '[' || c == '{') {
        brackets.push(c);
      } else if (!brackets.empty() && left_bracket(c) == brackets.top()) {
        brackets.pop();
      } else {
        return false;
      }
    }
    return brackets.empty();
  }

private:
  char left_bracket(char c) {
    char type = ')';
    switch (c) {
    case ')':
      type = '(';
      break;
    case ']':
      type = '[';
      break;
    case '}':
      type = '{';
      break;
    default:
      throw std::runtime_error("Invalid character");
      break;
    }
    return type;
  }
};

int main() {
  std::cout << key << ": 有效的括号" << std::endl;
  std::vector<std::tuple<std::string, bool>> test_cases = {
      std::make_tuple("()", true),   std::make_tuple("()[]{}", true),
      std::make_tuple("(]", false),  std::make_tuple("([)]", false),
      std::make_tuple("{[]}", true), std::make_tuple("]", false),
  };
  for (auto &&entry : test_cases) {
    auto input = std::get<std::string>(entry);
    auto expected = std::get<bool>(entry);
    bool output = Solution().isValid(input);
    std::cout << "input:" << input << " expected:" << expected
              << " output:" << output << std::endl;
  }
  return 0;
}

} // namespace leetcode_0020
