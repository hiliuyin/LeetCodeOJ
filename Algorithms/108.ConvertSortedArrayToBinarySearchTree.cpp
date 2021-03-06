// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    std::function<TreeNode*(int, int)> helper = [&](int low, int high) -> TreeNode* {
        if (low > high) return nullptr;
        int mid = low + (high - low)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(low, mid-1);
        root->right = helper(mid+1, high);
        return root;
    };
    
    return helper(0, nums.size()-1);
}
