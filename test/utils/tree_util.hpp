
#include <limits.h>

#include <vector>

#include "../../src/model/tree_node.hpp"

const int NULL_NODE_VAL = INT_MAX;

TreeNode *createBTree(const std::vector<int> &heap);

/**
 * @brief Free tree nodes.
 *
 * @param root
 */
void freeTreeNodes(TreeNode *root);

/**
 * @brief re-create heap from tree by travsaling level-orderly.
 *
 * @param root
 * @return std::vector<int>
 */
std::vector<int> levelOrder(TreeNode *root);

/**
 * @brief determine if tree left and tree right are the same.
 *
 * @param left
 * @param right
 * @return true
 * @return false
 */
bool treeEquals(TreeNode *left, TreeNode *right);
