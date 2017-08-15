/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree 
in which the depth of the two subtrees of every node never differ by more than 1.
*/

/*
From the problem description,
a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
Below is a representation of the tree input: {1,2,2,3,3,3,3,4,4,4,4,4,4,#,#,5,5}:

        ____1____
       /         \
      2           2
     /  \        / \
    3    3      3   3
   /\    /\    /\
  4  4  4  4  4  4 
 /\
5  5
Let's start with the root node (1). As you can see, left subtree's depth is 5, while right subtree's depth is 4. Therefore, the condition for a height-balanced binary tree holds for the root node. We continue the same comparison recursively for both left and right subtree, and we conclude that this is indeed a balanced binary tree.
*/

bool isBalanced(TreeNode* root) {
    if (root == nullptr) return true;

    std::function<int(TreeNode*)> getHeight = [&](TreeNode* node) {
        if (node == nullptr) return 0;
        return std::max(getHeight(node->left), getHeight(node->right)) + 1;
    };

    return std::abs(getHeight(root->left) - getHeight(root->right)) <= 1
        && isBalanced(root->left)
        && isBalanced(root->right);
}
