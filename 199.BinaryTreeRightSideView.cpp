/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
*/

std::vector<int> rightSideView(TreeNode* root)
{
    if (root == nullptr) return {};
    
    std::vector<int> result;
    std::queue<TreeNode*> Q;
    Q.push(root);
    Q.push(nullptr);
    
    TreeNode* prev = nullptr;
    while (!Q.empty())
    {
        auto node = Q.front();
        Q.pop();
        
        if (node == nullptr)
        {
            result.emplace_back(prev->val);
            if (!Q.empty())
                Q.push(nullptr);
        }
        else
        {
            if (node->left != nullptr)
                Q.push(node->left);
            if (node->right != nullptr)
                Q.push(node->right);
        }
        prev = node;
    }
    
    return result;
}
