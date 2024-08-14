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
    
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)return 0;
        int n=coins.size();
        vector<int> dp(amount+1,amount);
        dp[0] = 0;
        for(int i=1;i<=amount;++i){
            int minCnt = amount;
            for(int j=0;j<n;++j){
                if(i-coins[j]<0) continue;
                minCnt = min(minCnt,dp[i-coins[j]]);
            }
            dp[i] = minCnt + 1;
        }
        return dp[amount]>amount?-1:dp[amount];
    }
    
};


int main()
{
    Solution so;
    vector<int> coins = {1,2,5};
    int amount = 11;
    cout<<so.coinChange(coins,amount)<<endl;

    return 0;
}





