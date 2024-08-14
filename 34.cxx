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
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)
            return {-1,-1};
        int idx = mid(0,nums.size()-1,nums,target);
        if(idx==-1)
            return {-1,-1};
        int left = idx;
        int right = idx;
        while(--left >= 0 && nums[left]==nums[idx]);left+=1;
        while(++right < nums.size() &&nums[right]==nums[idx]);right-=1;
        return {left,right};
    }
    int mid(int begin,int end,const vector<int>& nums,const int target){
        if(begin==end)
            return nums[begin]==target?begin:-1;
        int midIdx = (begin+end)/2;
        if(nums[midIdx]==target)
            return midIdx;
        if(target<nums[midIdx])
            return mid(begin,midIdx,nums,target);
        else
            return mid(midIdx+1,end,nums,target);
    }
};

int main()
{
    Solution so;
    // vector<int> nums = {5,7,7,8,8,10};
    vector<int> nums = {1,1,2};
    so.print(so.searchRange(nums,1));
    return 0;
}