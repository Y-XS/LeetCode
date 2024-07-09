// 移除元素
#include <vector>
#include <algorithm>
#include <iostream>
#include<string>
#include<stack>
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


    void moveZeroes(vector<int>& nums) {
        int find0=0,find1=0;
        int n=nums.size();
        while(find1<n){
            while((find0<n) && (nums[find0]!=0))
                ++find0;
            while((find1<n) && (nums[find1]==0))
                ++find1;
            if(find1<find0){
                ++find1;
            }
            else if(find1<n&&find0<n){
                nums[find0] = nums[find1];
                nums[find1] = 0;
            }
        }
    }
};

int main()
{
    Solution so;
    // vector<int> nums = {0,1,0,3,12};
    vector<int> nums = {1,0};
    so.moveZeroes(nums);
    so.print(nums);
    return 0;
}