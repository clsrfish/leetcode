from typing import List, Optional

from src.model import TreeNode


class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        if len(nums) == 0:
            return None
        max_idx = 0
        for i in range(1, len(nums)):
            if nums[i] > nums[max_idx]:
                max_idx = i
        root = TreeNode(nums[max_idx])
        root.left = self.constructMaximumBinaryTree(nums[0:max_idx])
        root.right = self.constructMaximumBinaryTree(nums[max_idx + 1 :])

        return root
