/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }

        int val = sum - root->val;

        if ( val == 0 && root->left == NULL && root->right == NULL) {
            return true;
        }
        
        else
        {
            return hasPathSum(root->left, val) || hasPathSum(root->right, val);
        }
        
        return false;
    }
};
