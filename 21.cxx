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
    ListNode* makeList(vector<int> vec){
        ListNode *head,*q;
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
        return head;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode;
        ListNode* p = head;
        while(list1 && list2){
            if(list2->val<list1->val){
                p->next = list2;
                list2 = list2->next;
            }else{
                p->next = list1;
                list1 = list1->next;
            }
            p = p->next;
        }
        p->next = list1?list1:list2;
        return head->next;
    }
    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     ListNode* head = nullptr;
    //     ListNode* p = nullptr;
    //     ListNode* tmp = nullptr;
    //     while(list1 && list2){
    //         if(list2->val<list1->val){
    //             tmp = list2;
    //             list2 = list2->next;
    //         }else{
    //             tmp = list1;
    //             list1 = list1->next;
    //         }
    //         if(!head){
    //             head = tmp;
    //             p = head;
    //         }else{
    //             p->next = tmp;
    //             p = p->next;
    //         }
    //     }
    //     if(!head){
    //         return list1?list1:list2;
    //     }
    //     p->next = list1?list1:list2;
    //     return head;
    // }
};

int main()
{
    Solution so;

    vector<int> vec1 = {1,2,4};
    vector<int> vec2 = {1,3,4};
    auto list1 = so.makeList(vec1);
    auto list2 = so.makeList(vec2);
    // so.print(list1);
    // so.print(list2);
    auto list = so.mergeTwoLists(list1,list2);
    so.print(list);
    
    return 0;
}