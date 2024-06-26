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

    bool isValid(string s) {
        if(s.size()<=1)
            return false;
        stack<char> stk;
        for(auto c:s){
            if(c=='(' || c=='{' || c=='['){
                stk.push(c);
            }else{
                if(stk.size()>0){
                    char cc = stk.top();
                    if(c-cc >3 || cc-c>3)
                        return false;
                    else
                        stk.pop();
                }else{
                    return false;
                }
            }
        }
        return stk.empty();
    }
};

int main()
{
    string s = "[)(){}";
    Solution so;
    bool ret = so.isValid(s);
    cout<<ret<<endl;
    return 0;
}