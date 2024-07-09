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


    string removeTrailingZeros(string num) {
        auto it = num.end()-1;
        for(it;it!=num.begin();--it){
            if(*it != '0')
                break;
        }
        return string(num.begin(),it+1);
    }
};

int main()
{
    Solution so;
    string num = "51230100";
    cout<<so.removeTrailingZeros(num);
    return 0;
}