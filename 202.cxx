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

    bool isHappy(int n) {
        unordered_map<int,int> map;
        int num = n,sum=0;
        while(1){
            if(num == 1)
                return true;
            while(num/10 != 0){
                int x = num%10;
                sum += x*x;
                num/=10;
            }
            sum += num*num;
            num = sum;
            sum = 0;
            if(map[num]!=0)
                return false;
            map[num]++;
        }
    }
};

int main()
{
    Solution so;
    cout<<so.isHappy(2);
    return 0;
}