// 移除元素
#include <vector>
#include <algorithm>
#include <iostream>
#include<string>
#include<stack>
#include<unordered_set>
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

    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     vector<int> state;
    //     vector<bool> selected(nums.size(),false);
    //     ans.push_back(vector<int>());
    //     for(int i=0;i<nums.size();++i){
    //         backtrack(state,nums,selected,i+1,ans);
    //         selected.assign(nums.size(),false);
    //     }
    //     return ans;
    // }
    // void backtrack(vector<int> &state, const vector<int> &choices, vector<bool> &selected, int size, vector<vector<int>> &ans){
    //     if(state.size() == size){
    //         ans.push_back(state);
    //         return;
    //     }
    //     int used = 0;
    //     for(int i=0;i<choices.size();++i){
    //         if(!selected[i]){
    //             used = i;
    //             int choice = choices[i];
    //             selected[i] = true;
    //             state.push_back(choices[i]);

    //             backtrack(state,choices,selected,size,ans);
    //             state.pop_back();
    //             while(++used<choices.size())
    //                 selected[used] = false;
    //         }
    //     }
    // }

    //回溯思路
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size()==0)
            return ans;
        backtrack(0,nums);
        return ans;
    }
    vector<vector<int>> ans;
    vector<int> tmp;
    void backtrack(int idx,const vector<int> &nums){
        //判断边界条件
        if(nums.size() == idx){
            ans.push_back(tmp);
            return;
        }
        //不选
        backtrack(idx+1,nums);
        //选择
        tmp.push_back(nums[idx]);
        backtrack(idx+1,nums);
        tmp.pop_back();
    }

};

int main()
{
    Solution so;
    vector<int> nums = {1,2,3};
    auto ret = so.subsets(nums);
    for(auto vec:ret){
        so.print(vec);
    }
    return 0;
}