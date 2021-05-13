
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