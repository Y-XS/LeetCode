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
    

    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProf = 0;
        for(auto price:prices){
            minPrice = min(minPrice,price);
            maxProf = max(maxProf,price-minPrice);
        }
        return maxProf;
    }
};

int main()
{
    Solution so;

    return 0;
}