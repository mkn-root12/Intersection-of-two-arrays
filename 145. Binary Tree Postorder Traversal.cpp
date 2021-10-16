class Solution {
    vector<int> res;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return vector<int>{};

        stack<TreeNode*> cur;
        stack<TreeNode*> out;
        cur.push(root);
        while(!cur.empty()){
            TreeNode* temp = cur.top();cur.pop();
            out.push(temp);
            if(temp->left)
                cur.push(temp->left);
            if(temp->right)
                cur.push(temp->right);
        }
        while(!out.empty()){
            res.push_back(out.top()->val);out.pop();
        }
        return move(res);
    }
};
