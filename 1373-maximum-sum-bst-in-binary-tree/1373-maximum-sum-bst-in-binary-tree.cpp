class NodeValue {
public:
    int minNode;
    int maxNode;
    int sum;

    NodeValue(int minNode, int maxNode, int sum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};

class Solution {
private:
    int ans = 0;

    NodeValue MaxBST(TreeNode* root) {

        // Empty subtree
        if (root == nullptr) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        NodeValue left = MaxBST(root->left);
        NodeValue right = MaxBST(root->right);

        // Check whether current subtree is a BST
        if (left.maxNode < root->val &&
            root->val < right.minNode) {

            int currentSum = left.sum + root->val + right.sum;

            // Update maximum BST sum
            ans = max(ans, currentSum);

            return NodeValue(
                min(left.minNode, root->val),
                max(right.maxNode, root->val),
                currentSum
            );
        }

        // Not a BST
        // Return invalid range so parent cannot consider this subtree as BST
        return NodeValue(
            INT_MIN,
            INT_MAX,
            0
        );
    }

public:
    int maxSumBST(TreeNode* root) {
        ans = 0;
        MaxBST(root);
        return ans;
    }
};