/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root)
{
    if (root == nullptr) return {};
    
    std::vector<std::vector<int>> result;
    std::vector<int> row;
    
    std::queue<TreeNode*> Q;
    Q.push(root);
    Q.push(nullptr);
    int level = 0;
    while (!Q.empty())
    {
        auto node = Q.front();
        Q.pop();
        
        if (node == nullptr)
        {
            result.emplace_back(row);
            if (!Q.empty())
            {
                row.clear();
                Q.push(nullptr);
                ++level;
            }
        }
        else
        {
            if (level%2 == 0)
                row.emplace_back(node->val);
            else
                row.emplace(row.begin(), node->val);

            if (node->left != nullptr)
                Q.push(node->left);
            if (node->right != nullptr)
                Q.push(node->right);
        }
    }
    
    return result;
}
