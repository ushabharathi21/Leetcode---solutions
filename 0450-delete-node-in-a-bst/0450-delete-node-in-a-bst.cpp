
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

        // If root itself is the node to delete
        if (root->val == key)
            return helper(root);

        TreeNode* dummy = root;

        while (root != NULL) {

            // Key is in left subtree
            if (root->val > key) {

                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                }
                else {
                    root = root->left;   // ✅ FIXED
                }
            }

            // Key is in right subtree
            else {

                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                }
                else {
                    root = root->right;
                }
            }
        }

        return dummy;
    }

    TreeNode* helper(TreeNode* root) {

        // No left child
        if (root->left == NULL)
            return root->right;

        // No right child
        else if (root->right == NULL)
            return root->left;

        // Both children exist
        TreeNode* rightChild = root->right;

        TreeNode* lastRight = findLastRight(root->left);

        lastRight->right = rightChild;

        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root) {

        if (root->right == NULL)
            return root;

        return findLastRight(root->right);
    }
};
