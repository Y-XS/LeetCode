// 移除元素
#include <vector>
#include <algorithm>
#include <iostream>
#include<string>
#include<stack>
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
    void print(string s)
    {
        cout << s << endl;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> state;
        vector<bool> selected(nums.size(),false);
        backtrack(state,nums,selected,ans);
        return ans;
    }
    void backtrack(vector<int> &state, const vector<int> &choices, vector<bool> &selected, vector<vector<int>> &ans){
        if(state.size() == choices.size()){
            ans.push_back(state);
            return;
        }
        for(int i=0;i<choices.size();++i){
            if(!selected[i]){
                int choice = choices[i];
                selected[i] = true;
                state.push_back(choices[i]);
                backtrack(state,choices,selected,ans);
                selected[i] = false;
                state.pop_back();
            }
        }
    }
};

int main()
{
    Solution so;
    return 0;
}