/**
 * @file 0145.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 二叉树的后序遍历 https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
 * @version 0.1
 * @date 2021-04-27
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <vector>

#include "../model/tree_node.hpp"
#include "../utils/stl_utils.hpp"

namespace leetcode_0145 {
std::string key = "0145";
class Solution {
 public:
  std::vector<int> postorderTraversal(TreeNode* root) {
    std::vector<int> res;
    postorderTraversalRecursively(root, res);
    return res;
  }

 private:
  void postorderTraversalRecursively(TreeNode* root, std::vector<int>& res) {
    if (root == nullptr) {
      return;
    }
    postorderTraversalRecursively(root->left, res);
    postorderTraversalRecursively(root->right, res);
    res.push_back(root->val);
  }
};
int main() {
  std::cout << key << ": 二叉树的后序遍历" << std::endl;
  auto root = new TreeNode(1);
  root->right = new TreeNode(2, new TreeNode(3), nullptr);
  auto res = Solution().postorderTraversal(root);
  std::cout << vector2str(res) << std::endl;
  return 0;
}
}  // namespace leetcode_0145