class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void solve(int idx, int target, vector<int>& candidates) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (idx == candidates.size() || target < 0)
            return;

        curr.push_back(candidates[idx]);
        solve(idx, target - candidates[idx], candidates);
        curr.pop_back();

        solve(idx + 1, target, candidates);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0, target, candidates);
        return ans;
    }
};