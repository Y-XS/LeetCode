// 移除元素
#include <vector>
#include <algorithm>
#include <iostream>
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

    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2)
            return 2;
        int flag=0,len=0,times=0;
        for(int i=0;i<nums.size();++i){
            if(flag==nums[i]){
                ++times;
                if(len!=i)
                    nums[len] = nums[i];
                if(times<=2)
                    ++len;
            }else{
                flag = nums[i];
                times = 1;
                //交换len、i
                nums[len] = nums[i];
                ++len;
            }
        }
        return len;
    }
};

int main()
{
    Solution so;
    vector<int> vec = {1,1,1,2,2,3};
    int len =so.removeDuplicates(vec);
    cout<<len<<endl;
    so.print(vec);
    return 0;
}