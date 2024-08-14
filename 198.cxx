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
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        if(n==3) return max(nums[1],nums[0]+nums[2]);
        nums[2] += nums[0];
        int maxVal = max(nums[1],nums[2]);
        for(int i=3;i<nums.size();++i){
            nums[i] += max(nums[i-2],nums[i-3]);
            maxVal = max(maxVal,nums[i]);
        }
        return maxVal;
    }
    
};

int main()
{
    Solution so;
    vector<int> vec = {1,2,3,1};
    cout<<so.rob(vec)<<endl;
    return 0;
}