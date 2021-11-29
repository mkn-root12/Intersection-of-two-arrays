Solution 1. Union Find
Complexity Analysis
Let N be the length of A, M be the maximum length of A[i], W is the maximum email string length.

Filling emailToIndex takes O(NMW) time and O(NMW) space.

The UnionFind takes O(N) space.

Connecting nodes in the UnionFind takes O(NMW) time.

Filling the idToEmail takes O(NMWlog(NM)) time and O(NMW) space.

Gathering the answer takes O(NMW) time.

So, overall it takes O(NMWlog(NM)) time and O(NMW) space.

// OJ: https://leetcode.com/problems/accounts-merge/
// Author: github.com/lzl124631x
// Time: O(NMWlog(NM))
// Space: O(NMW)
class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int x) {
        return id[x] == x ? x : (id[x] = find(id[x]));
    }
    void connect(int a, int b) {
        id[find(a)] = find(b);
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& A) {
        unordered_map<string, int> emailToIndex;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 1; j < A[i].size(); ++j) emailToIndex[A[i][j]] = i;
        }
        UnionFind uf(A.size());
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 1; j < A[i].size(); ++j) uf.connect(i, emailToIndex[A[i][j]]);
        }
        unordered_map<int, set<string>> idToEmail;
        for (int i = 0; i < A.size(); ++i) {
            auto &st = idToEmail[uf.find(i)];
            for (int j = 1; j < A[i].size(); ++j) st.insert(A[i][j]);
        }
        vector<vector<string>> ans;
        for (auto &[id, emails] : idToEmail) {
            ans.push_back({A[id][0]});
            for (auto &email : emails) ans.back().push_back(email);
        }
        return ans;
    }
};




Solution 2. DFS
We first build a graph where the nodes are the emails. If two emails belongs to the same person, we will add an edge between them.

Then we traverse the A, and dfs to visit all the nodes in the same graph component. When visting, we append the emails to the person's email list.

Complexity Analysis
Building the graph takes O(NMW) time and O(NMW) space.

Visiting all the components will take O(NMW) time and O(NMW) space for the seen.

Sorting the emails in the components takes O(NMWlog(NM)) time overall.

So the time complexity is O(NMWlog(NM)) and space complexity is O(NMW).

// OJ: https://leetcode.com/problems/accounts-merge/
// Author: github.com/lzl124631x
// Time: O(NMWlog(NM))
// Space: O(NMW)
class Solution {
    unordered_map<string, unordered_set<string>> G;
    unordered_set<string> seen;
    vector<vector<string>> ans;
    void dfs(const string &s) {
        if (seen.count(s)) return;
        seen.insert(s);
        ans.back().push_back(s);
        for (const auto &nei : G[s]) {
            dfs(nei);
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& A) {
        for (auto &v : A) {
            for (int i = 1; i < v.size(); ++i) {
                G[v[1]].insert(v[i]);
                G[v[i]].insert(v[1]);
            }
        }
        for (int i = 0; i < A.size(); ++i) {
            if (seen.count(A[i][1])) continue;
            ans.push_back({A[i][0]});
            dfs(A[i][1]);
            sort(begin(ans.back()) + 1, end(ans.back()));
        }
        return ans;
    }
};
