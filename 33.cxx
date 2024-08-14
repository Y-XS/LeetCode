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
    
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        int idx = 0;
        while(left<right){
            if(nums[left]<=nums[right]){
                idx = left == right? left+1 : left;
                break;
            }
            ++left;
            --right;
        }
        if(target>nums[0])
            return mid(0,idx-1,nums,target);
        else
            return mid(idx,nums.size()-1,nums,target);
    }
    int mid(int begin,int end,const vector<int>& nums,const int target){
        if(begin==end)
            return nums[begin]==target?begin:-1;
        int midIdx = (begin+end)/2;
        if(nums[midIdx]>nums[midIdx+1])
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
    return 0;
}