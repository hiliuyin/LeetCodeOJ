/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

// BFS
std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) return {};

    std::vector<std::vector<int>> result;
    std::vector<int> level;
    std::queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        
        if (node != nullptr) {
            level.emplace_back(node->val);
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
        else {
            result.emplace_back(level);
            if (!q.empty()) {
                level.clear();
                q.push(nullptr);
            }
        }
    }
    return result;
}


