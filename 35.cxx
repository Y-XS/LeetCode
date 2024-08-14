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
    
    int searchInsert(vector<int>& nums, int target) {
        return mid(0,nums.size()-1,nums,target);
    }
    int mid(int begin,int end,const vector<int>& nums,const int target){
        if(begin==end)
            return target>nums[begin]?begin+1:begin;
        int midIdx = (begin + end)/2;
        if(nums[midIdx]==target)
            return midIdx;
        if(target<nums[midIdx])
            midIdx = mid(begin,midIdx,nums,target);
        else
            midIdx = mid(midIdx+1,end,nums,target);
        return midIdx;
    }
};

int main()
{
    Solution so;
    vector<int> nums = {1,3,5,6};
    cout<< so.searchInsert(nums,7);
    return 0;
}