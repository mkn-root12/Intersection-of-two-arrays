class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        
        if(root) q.push(root);
        
        while(!q.empty()){
            int level_size = q.size();
            
            vector<int> level;
            
            while(level_size-- > 0){
                TreeNode* cur = q.front(); q.pop();
                
                level.push_back(cur->val);
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            
            ans.push_back(level);
        }
        
        return ans;
    }
};
