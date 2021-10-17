class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if(root == nullptr)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        
        while(!q.empty())
        {
            int count = q.size();
            while(count--)
            {
                TreeNode* n = q.front();
                q.pop();
                
                if(n->left)
                    q.push(n->left);
                if(n->right)
                    q.push(n->right);
            }
            
            depth++;
        }
        
        return depth;
    }
};
