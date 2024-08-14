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

    vector<string> map = {"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    string path;
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return ans;
        backtrack(0,digits);
        return ans;
    }
    void backtrack(int idx,string digits){
        //边界条件
        if(idx==digits.size()){
            ans.push_back(path);
            return;
        }
        //选择
        string str = map[digits[idx]-'0'-1];
        for(int i=0;i<str.size();++i){
            path.push_back(str[i]);
            backtrack(idx+1,digits);
            path.pop_back();
        }
    }
};

int main()
{
    Solution so;
    string digits = "23";
    auto ret = so.letterCombinations(digits);
    for(auto s:ret){
        cout<<s<<endl;
    }
    return 0;
}