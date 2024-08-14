// 移除元素
#include <vector>
#include <algorithm>
#include <iostream>
#include<string>
#include<stack>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution
{
public:
    void print(vector<int> nums)
    {
        for (auto item : nums)
        {
            cout << item << " ";
        }
        cout << endl;
    }
    void print(vector<bool> vec)
    {
        for (auto item : vec)
        {
            cout << item << " ";
        }
        cout << endl;
    }
    void print(string s)
    {
        cout << s << endl;
    }

    // vector<vector<int>> ans;
    // vector<int> path;
    // unordered_map<int,int> path_cnt;
    // vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //     backtrack(0,target,candidates);
    //     return ans;
    // }
    // void backtrack(int idx,const int &target,const vector<int> &candidates){
    //     if(idx == candidates.size()){
    //         return;
    //     }
    //     if(0 == target){
    //         ans.push_back(path);
    //         return;
    //     }
    //     backtrack(idx+1,target,candidates);
    //     if(target-candidates[idx] >= 0){
    //         path.emplace_back(candidates[idx]);
    //         // 注意此处 idx
    //         backtrack(idx,target-candidates[idx],candidates);
    //         path.pop_back();
    //     }
    // }

    vector<string> ans;
    string path;
    vector<string> generateParenthesis(int n) {
        dfs(n,0,0);
        return ans;
    }
    void dfs(const int &n,int left,int right){
        if(left > n)
            return;
        if(path.size() == 2*n){
            ans.push_back(path);
            return;
        }
        // 放左
        path.push_back('(');
        dfs(n,left+1,right);
        path.pop_back();
        // 放右
        if(left > right){
            path.push_back(')');
            dfs(n,left,right+1);
            path.pop_back();
        }
    }
};

int main()
{
    Solution so;
    vector<int> nums = {1,2,3};
    
    return 0;
}