/*
You are given a binary tree in which each node contains an integer value.
Find the number of paths that sum to a given value.
The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1
Return 3. The paths that sum to 8 are:
1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
*/

int pathSum(TreeNode* root, int sum) {
    if (root == nullptr) return 0;

    int res = 0;
    std::function<void(TreeNode*, int)> helper = [&](TreeNode* node, int val) {
        if (node == nullptr) return;
        if (node->val == val) ++res;
        helper(node->left, val - node->val);
        helper(node->right, val - node->val);
    };
    
    std::stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
        auto node = s.top();
        s.pop();
        helper(node, sum);
        if (node->left != nullptr) s.push(node->left);
        if (node->right != nullptr) s.push(node->right);
    }
    
    return res;
}
