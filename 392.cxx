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

    bool isSubsequence(string s, string t) {
        string::iterator its = s.begin();
        string::iterator itt = t.begin();
        if(s==t)
            return true;
        while(itt != t.end()){
            cout<<*its<<" "<<*itt<<endl;
            if(*its == *itt)
                ++its;
            if(its == s.end())
                return true;
            ++itt;
        }
        return false;
    }
};

int main()
{
    Solution so;
    // string s = "A man, a plan, a canal: Panama";
    // string s = "race a car";
    string s = "";
    string t = "";
    cout << so.isSubsequence(s,t);
    return 0;
}