// 移除元素
#include <vector>
#include <algorithm>
#include <iostream>
#include<string>
#include<unordered_map>
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

    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0)
            return {};
        vector<string> vec;
        int start=nums[0],end=nums[0];
        if(nums.size()==1)
            return {to_string(start)};
        for(int i=1;i<nums.size();++i){
            if(nums[i]!=end+1){
                vec.push_back(end==start?to_string(start):to_string(start)+"->"+to_string(end));
                start = nums[i];
            }
            end = nums[i];
            if(i==nums.size()-1)
                vec.push_back(end==start?to_string(start):to_string(start)+"->"+to_string(end));
        }
        return vec;
    }
};

int main()
{
    vector<int> nums = {0,1,2,4,5,7};
    // vector<int> nums = {0,2,3,4,6,8,9};
    Solution so;
    vector<string> ret = so.summaryRanges(nums);
    for_each(ret.begin(),ret.end(),[](string item){cout<<item<<endl;});
    return 0;
}