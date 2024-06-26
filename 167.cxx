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

    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int right=numbers.size()-1;
        while(left<numbers.size() && right>left){
            if(numbers[left] + numbers[right] == target)
                return {left+1,right+1};
            else if(numbers[left] + numbers[right] > target)
                --right;
            else
                ++left;
        }
        return {};
    }
};

int main()
{
    Solution so;
    vector<int> vec = {2,7,11,15};
    // vector<int> vec = {-1,-1,11,15};
    vector<int> ret = so.twoSum(vec,9);
    so.print(ret);
    cout<<((-1+-1)==-2) <<endl;
    return 0;
}