/*
You need to find the largest value in each row of a binary tree.

Example:
Input: 
          1
         / \
        3   2
       / \   \  
      5   3   9 
Output: [1, 3, 9]
*/

// BFS
vector<int> largestValues(TreeNode* root) {
    if (root == nullptr) return {};
    
    std::vector<int> res;
    std::queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);
    int maxVal = INT_MIN;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        
        if (node == nullptr) {
            res.emplace_back(maxVal);
            maxVal = INT_MIN;
            if (!q.empty()) {
                q.push(nullptr);
            }
        }
        else {
            maxVal = std::max(maxVal, node->val);
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
    }
    
    return res;
}
