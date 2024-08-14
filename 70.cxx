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
    
    int climbStairs(int n) {
        if(n==1||n==2)
            return n;
        int a=1,b=2;
        for(int i=3;i<=n;++i){
            int tmp=b;
            b=a+b;
            a= tmp;
        }
        return b;
    }
    
};

int main()
{
    Solution so;

    return 0;
}