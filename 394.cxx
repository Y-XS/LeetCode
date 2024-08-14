// 移除元素
#include <vector>
#include <algorithm>
#include <iostream>
#include<string>
#include<stack>
#include<unordered_set>
#include<unordered_map>
#include <thread>
#include <chrono>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> stk_cnt;
        stack<string> stk_str;
        string curStr = "";
        int k = 0;
        for(auto c:s){
            if(isdigit(c)){
                k = k*10 + c-'0';
            }
            else if(c=='['){
                stk_cnt.push(k);k=0;
                stk_str.push(curStr);curStr="";
            }
            else if(c==']'){
                int times = stk_cnt.top();stk_cnt.pop();
                string tmp = stk_str.top();stk_str.pop();
                while(times--)
                    tmp+=curStr;
                curStr = tmp;
            }
            else{
                curStr += c;
            }
        }
        return curStr;
    }
};


int main()
{
    return 0;
}