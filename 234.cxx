// 移除元素
#include <vector>
#include <algorithm>
#include <iostream>
#include<string>
#include<stack>
#include<unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    void print(ListNode* list){
        while(list){
            cout<<list->val<<" ";
            list = list->next;
        }
        cout<<endl;
    }

    bool isPalindrome(ListNode* head) {
        stack<int> stk;
        ListNode* p = head;
        while(p){
            stk.push(p->val);
            p = p->next;
        }
        p = head;
        while(p){
            if(p->val!=stk.top()){
                return false;
            }
            stk.pop();
            p = p->next;
        }
        return true;
    }
};

int main()
{
    Solution so;
    ListNode *head,*q;
    vector<int> vec = {1,0,1};

    for(int i=0;i<vec.size();++i){
        ListNode* node = new ListNode;
        node->val = vec[i];
        node->next = nullptr;
        if(i==0){
            q = node;
            head = q;
        }else{
            q->next = node;
            q=q->next;
        }
    }
    so.print(head);
    cout<<(so.isPalindrome(head)?"True":"false")<<endl;

    return 0;
}