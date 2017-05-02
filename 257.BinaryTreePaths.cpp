/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:
   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:
["1->2->5", "1->3"]
*/

// solution 1: recursive
std::vector<std::string> binaryTreePaths(TreeNode* root) {
    std::vector<std::string> result;
    std::string s;
    std::function<void(TreeNode*, const std::string&)> helper =
        [&](TreeNode* root, const std::string& path) {
        if (root == nullptr) return;

        if (root->left == nullptr && root->right == nullptr) {
            result.emplace_back(path + std::to_string(root->val));
            return;
        }
        
        if (root->left != nullptr)
            helper(root->left, path + std::to_string(root->val) + "->");
        if (root->right != nullptr)
            helper(root->right, path + std::to_string(root->val) + "->");
    };
    
    helper(root, s);
    return result;
}

