// 移除元素
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    // int removeElement(vector<int> &nums, int val)
    // {
    //     int left = 0;
    //     int right = nums.size()-1;
    //     int cnt = 0;
    //     while (left < right)
    //     {
    //         while (nums[right] == val)
    //         {
    //             right--;
    //             cnt++;
    //         }
    //         while (nums[left] == val)
    //         {
    //             nums[left] = nums[right];
    //             right--;
    //             cnt++;
    //         }
    //         left++;
    //     }
    //     return nums.size() - cnt;
    // }

    int removeElement(vector<int> &nums, int val)
    {
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            if(nums[left]==val){
                nums[left] = nums[right-1];
                right--;
            }else{
                left++;
            }
        }
        return left;
    }

    //     int removeElement(vector<int>& nums, int val) {
    //     int n = nums.size();
    //     int left = 0;
    //     for (int right = 0; right < n; right++) {
    //         if (nums[right] != val) {
    //             nums[left] = nums[right];
    //             left++;
    //         }
    //     }
    //     print(nums);
    //     cout<<left;
    //     return left;
    // }

    void print(vector<int> nums)
    {
        for (auto item : nums)
        {
            cout << item << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution so;
    vector<int> vec = {0,1,2,2,3,0,4,2};
    // vector<int> vec = {1};
    cout << so.removeElement(vec, 2);
    return 0;
}