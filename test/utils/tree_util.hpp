
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
 * @brief determine if tree a and b are the same.
 *
 * @param a
 * @param b
 * @return true, a is same as b
 * @return false, if not the same
 */
bool treeEquals(TreeNode *a, TreeNode *b);