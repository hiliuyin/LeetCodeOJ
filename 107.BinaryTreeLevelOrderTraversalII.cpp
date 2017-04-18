/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
    if (root == nullptr) return {};
    
    std::vector<std::vector<int>> result;
    std::vector<int> level;
    
    std::queue<TreeNode*> Q;
    Q.push(root);
    Q.push(nullptr);
    
    while (!Q.empty()) {
        auto node = Q.front();
        Q.pop();
        if (node == nullptr) {
            result.emplace(result.begin(), level);
            if (!Q.empty()) {
                level.clear();
                Q.push(nullptr);
            }
        }
        else {
            level.emplace_back(node->val);
            if (node->left != nullptr)
                Q.push(node->left);
            if (node->right != nullptr)
                Q.push(node->right);
        }
    }
    
    return result;
}
