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


    string simplifyPath(string path) {
        auto split = [](const string& s,char delim){
            vector<string> ans;
            string cur;
            for(auto c:s){
                if(c==delim){
                    ans.push_back(cur);
                    cur.clear();
                }else{
                    cur+=c;
                }
            }
            ans.push_back(cur);
            return ans;
        };
        vector<string> seps = split(path,'/');
        vector<string> stk;//只是借用了栈的概念
        for(auto name:seps){
            if(name == ".."){
                if(!stk.empty())
                    stk.pop_back();
            }else if(!name.empty() && name != "."){
                stk.push_back(name);
            }
        }
        string ret;
        if(stk.empty())
            ret = "/";
        for(auto c:stk){
            ret += "/" + c;
        }
        return ret;
    }
};

int main()
{
    Solution so;
    string path = "/../";
    cout<<so.simplifyPath(path)<<endl;
    return 0;
}