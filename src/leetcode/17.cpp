/**
 * @file 0017.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 电话号码的字母组合:
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
 * @version 0.1
 * @date 2021-01-11
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <vector>
namespace leetcode_0017 {
std::string key = "0017";
class Solution {
private:
  static std::vector<std::vector<char>> mapping;

public:
  std::vector<std::string> letterCombinations(const std::string &digits) {
    std::vector<std::string> result;
    if (digits.length() == 0) {
      return result;
    }
    std::string path;
    backtrace(digits, path, result);
    return result;
  }

  void backtrace(const std::string &digits, std::string &path,
                 std::vector<std::string> &result) {
    size_t index = path.length();
    if (index == digits.length()) {
      result.push_back(path);
      return;
    }

    std::vector<char> &choices = mapping[digits[index] - '2'];
    for (auto &&c : choices) { // auto&& avoid memory copying
      path.push_back(c);
      backtrace(digits, path, result);
      path.pop_back();
    }
  }
};

std::vector<std::vector<char>> Solution::mapping = {
    {'a', 'b', 'c'}, {'d', 'e', 'f'},      {'g', 'h', 'i'},
    {'j', 'k', 'l'}, {'m', 'n', 'o'},      {'p', 'q', 'r', 's'},
    {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'},
};

int main() {
  std::cout << key << ":电话号码的字母组合" << std::endl;
  const std::string input = "23";
  const std::vector<std::string> expected = {"ad", "ae", "af", "bd", "be",
                                             "bf", "cd", "ce", "cf"};
  auto result = Solution().letterCombinations(input);
  auto &out = std::cout << "result  : [";
  for (auto &r : result) {
    out << r << ", ";
  }
  out << "]\n"
      << "expected: [";
  for (auto &r : expected) {
    out << r << ", ";
  }
  out << "]\n" << std::endl;

  return 0;
}
} // namespace leetcode_0017
