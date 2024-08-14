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

class MinStack {
public:
    stack<int> stk;
    stack<int> stk_min;
    MinStack() {
        stk_min.push(INT_MAX);
    }
    
    void push(int val) {
        stk.push(val);
        stk_min.push(min(stk_min.top(),val));
    }
    
    void pop() {
        stk.pop();
        stk_min.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return stk_min.top();
    }
};


int main()
{
    return 0;
}