/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

std::vector<int> postorderTraversal(TreeNode* root)
{
    if (root == nullptr) return {};

    std::vector<int> result;
    std::stack<TreeNode*> S;
    
    S.push(root);
    TreeNode *prev = nullptr;
    while (!S.empty())
    {
        auto curr = S.top();
        
        // curr结点的左右子树尚未处理
        if (prev == nullptr || curr == prev->left || curr == prev->right)
        {
            if (curr->left != nullptr)
                S.push(curr->left);
            else if (curr->right != nullptr)
                S.push(curr->right);
        }
        // curr结点的左子树已经全部处理完毕
        else if (curr->left == prev)
        {
            if (curr->right != nullptr)
                S.push(curr->right);
        }
        // curr结点的左右子树全部处理完毕，包括curr本身是叶子结点的情况
        else
        {
            S.pop();
            result.emplace_back(curr->val);
        }
        prev = curr;
    }
    
    return result;
}
