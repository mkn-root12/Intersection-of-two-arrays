985. Sum of Even Numbers After Queries

/*solution*/
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res;
        int n = A.size(), even = 0;
        for (int num : A) {
            if (num % 2 == 0) even += num;
        }
        for (auto &query : queries) {
            int old = A[query[1]], cur = old + query[0];
            if (old % 2 == 0) even -= old;
            if (cur % 2 == 0) even += cur;
            A[query[1]] = cur;
            res.push_back(even);
        }
        return res;
    }
};





