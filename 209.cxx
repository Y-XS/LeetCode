// 移除元素
#include <vector>
#include <algorithm>
#include <iostream>
#include<string>
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
    void print(string s)
    {
        cout << s << endl;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size()==0)return 0;
        int sum = 0,minCnt=nums.size()+1;
        int left=0,right=0;
        while(right < nums.size()){
            sum += nums[right];
            while(sum >= target){
                minCnt = min(minCnt,right-left+1);
                sum-=nums[left];
                ++left;
            }
            ++right;
        }
        return minCnt==nums.size()+1?0:minCnt;
    }
};

int main()
{
    Solution so;
    vector<int> vec = {2,3,1,2,4,3};
    // vector<int> vec = {-1,-1,11,15};
    cout << so.minSubArrayLen(7,vec);
    return 0;
}