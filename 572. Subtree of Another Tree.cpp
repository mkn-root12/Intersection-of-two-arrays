class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) return true;
        if (s == NULL || t == NULL) return false;
        if (s->val == t->val && isSame(s, t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
private:
    bool isSame(TreeNode* r, TreeNode* t) {
        if (r == NULL && t == NULL) return true;
        if (r == NULL || t == NULL || r->val != t->val) return false;
        return (isSame(r->left, t->left) && isSame(r->right, t->right));
    }
};
