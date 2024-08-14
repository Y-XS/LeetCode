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
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto vec:matrix){
            if(target>vec.back())
                continue;
            return mid(0,vec.size()-1,vec,target);
        }
    }
    bool mid(int begin,int end,const vector<int>& nums,const int target){
        if(begin==end)
            return target==nums[begin]?true:false;
        int midIdx = (begin+end)/2;
        if(nums[midIdx]==target)
            return true;
        if(target < nums[midIdx])
            return mid(begin,midIdx,nums,target);
        else
            return mid(midIdx+1,end,nums,target);
    }
};

int main()
{
    Solution so;
    vector<int> nums = {1,3,5,6};
    return 0;
}