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
    
    int numSquares(int n) {
        vector<int> f(n+1);
        for(int i=1;i<=n;++i){
            int minCnt = INT_MAX;
            for(int j=1;j*j<=i;++j){
                minCnt = min(minCnt,f[i-j*j]);
            }
            f[i] = minCnt+1;
        }
        return f[n];
    }
    
};

int main()
{
    Solution so;
    return 0;
}