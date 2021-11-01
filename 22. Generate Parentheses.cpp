class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string par = "";
        helper(res, par, n, n);
        return res;
        
    }
    void helper(vector<string> &res, string &par, int lefttoadd, int righttoadd) {
        if (lefttoadd > righttoadd || lefttoadd < 0 || righttoadd < 0) {
            return;
        }
        if (lefttoadd == 0 && righttoadd == 0) {
            res.push_back(par);
            return;
        }
        par += "(";
        helper(res, par, lefttoadd - 1, righttoadd);
        par.pop_back();
        par += ")";
        helper(res, par, lefttoadd, righttoadd - 1);
        par.pop_back();
        return;
    }
};
