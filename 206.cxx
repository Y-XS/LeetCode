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

    // ListNode* reverseList(ListNode* head) {
    //     ListNode* list;
    //     ListNode* p = head;
    //     stack<ListNode*> stk;
    //     while(p){
    //         stk.push(p);
    //         p = p->next;
    //     }
    //     int size = stk.size();
    //     for(int i=0;i<size;++i){
    //         if(i==0){
    //             list = stk.top();
    //             p = list;
    //         }else{
    //             p->next = stk.top();
    //             p = p->next;
    //         }
    //         stk.pop();
    //     }
    //     p->next = nullptr;
    //     return list;
    // }

    // 头插法next会变，不适用
    ListNode* reverseList(ListNode* head) {
        ListNode* rhead = nullptr;
        ListNode* p=head;
        ListNode* tmp;
        while(p){
            if(!rhead){
                rhead = p;
            }else{
                tmp->val = p->val;
                tmp->next = rhead;
                rhead = tmp;
            }
            cout<<p->val<<endl;
            p = p->next;
        }
        return rhead;
    }
    
};

int main()
{
    Solution so;
    // vector<int> nums = {0,1,0,3,12};
    ListNode* head;
    ListNode* q;
    for(int i=0;i<5;++i){
        ListNode* p = new ListNode;
        p->next=nullptr;
        p->val=i+1;
        if(i==0){
            q = p;
            head = q;
        }else{
            q->next = p;
            q=q->next;
        }
        q->next = nullptr;
    }
    so.print(head);
    ListNode* rhead = so.reverseList(head);
    so.print(rhead);
    return 0;
}