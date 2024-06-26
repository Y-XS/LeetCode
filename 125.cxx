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

    bool isPalindrome(string s) {
        if(s=="")
            return true;
        string ss;
        for(auto c:s){
            if(('0'<=c && c<='9') || ('A'<=c && c<='Z') || ('a'<=c && c<='z')){
                ss+=c;
            }
        }
        string::iterator left = ss.begin();
        string::iterator right = ss.end()-1;
        while(left<right){
            cout<<*left<<" "<<*right<<" "<<(*left-*right)<<" "<<'A'-'a'<<endl;
            if(*left != *right){
                if((*left-*right)!=('A'-'a') && (*left-*right)!=('a'-'A')){
                    return false;
                }
            }
            ++left;
            --right;
        }
        return true;
    }
};

int main()
{
    Solution so;
    // string s = "A man, a plan, a canal: Panama";
    // string s = "race a car";
    string s = "0P";
    cout << so.isPalindrome(s)<<endl;
    so.print(s);
    return 0;
}