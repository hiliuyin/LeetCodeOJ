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

std::vector<std::string> binaryTreePaths(TreeNode* root)
{
    if (root == nullptr) return {};

    std::vector<std::string> result;
    std::string path;

    std::function<void(TreeNode*)> helper = [&](TreeNode* root)
    {
        if (root == nullptr) return;
        
        path += std::to_string(root->val) + "->";
        if (root->left == nullptr && root->right == nullptr)
        {
            result.emplace_back(path.substr(0, path.size()-2));
        }
        else
        {
            helper(root->left);
            helper(root->right);
        }
        
        path.pop_back();
        path.pop_back();
        auto pos = path.find_last_of(">");
        path.erase(pos+1);
    };
    
    helper(root);

    return result;
}
