/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

std::vector<std::vector<int>> pathSum(TreeNode* root, int sum)
{
    if (root == nullptr) return {};
    
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    
    std::function<void(TreeNode*, int)> helper = [&](TreeNode* root, int sum)
    {
        if (root == nullptr) return;
        
        path.emplace_back(root->val);
        if (root->left == nullptr && root->right == nullptr && root->val == sum)
        {
            result.emplace_back(path);
        }
        else
        {
            helper(root->left, sum - root->val);
            helper(root->right, sum - root->val);
        }
        path.pop_back();
    };
    
    helper(root, sum);
    
    return result;
}
