// 移除元素
#include <vector>
#include <algorithm>
#include <iostream>
#include<string>
#include<stack>
#include<unordered_set>
#include<unordered_map>
#include <thread>
#include <chrono>
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
    
    vector<vector<int>> generate(int numRows) {
        if(numRows==0)
            return {{}};
        vector<vector<int>> ans(numRows);
        for(int i=0;i<numRows;++i){
            ans[i].resize(i+1);
            for(int j=0;j<=i;++j){
                if(j==0||j==i){
                    ans[i][j]=1;
                    continue;
                }
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans;
    }
    
};

int main()
{
    Solution so;
    auto vvec = so.generate(5);
    for(auto vec:vvec){
        so.print(vec);
    }
    return 0;
}