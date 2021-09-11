
#include "./tree_util.hpp"

#include <deque>

TreeNode *createBTree(const std::vector<int> &heap, unsigned int nodeIndex) {
  if (heap.size() <= nodeIndex) {
    return nullptr;
  }
  int val = heap[nodeIndex];
  if (val == NULL_NODE_VAL) {
    return nullptr;
  }
  TreeNode *node = nullptr;
  node = new TreeNode(val);
  unsigned int nodeIndexLeft = nodeIndex * 2 + 1;
  node->left = createBTree(heap, nodeIndexLeft);
  node->right = createBTree(heap, nodeIndexLeft + 1);
  return node;
}

TreeNode *createBTree(const std::vector<int> &heap) {
  TreeNode *root = createBTree(heap, 0);

  return root;
}

void freeTreeNodes(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  freeTreeNodes(root->left);
  freeTreeNodes(root->right);
  delete root;
}

std::vector<int> levelOrder(TreeNode *root) {
  std::vector<int> res;
  std::vector<TreeNode *> queueA, queueB;
  queueA.emplace_back(root);
  while (!queueA.empty()) {
  }
  return res;
}

bool treeEquals(TreeNode *left, TreeNode *right) {
  if (left == nullptr && right == nullptr) {
    return true;
  }
  if ((left != nullptr && right == nullptr) || (left == nullptr && right != nullptr)) {
    return false;
  }
  if (left->val != right->val) {
    return false;
  }

  return treeEquals(left->left, right->left) && treeEquals(left->right, right->right);
}