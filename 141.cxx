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
    ListNode(int x) : val(x), next(NULL) {}
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
    // 经典哈希表
    // bool hasCycle(ListNode *head) {
    //     unordered_set<ListNode*> set;
    //     ListNode* p = head;
    //     while(p){
    //         if(set.count(p)!=0)
    //             return true;
    //         set.insert(p);
    //         p=p->next;
    //     }
    //     return false;
    // }
    // 快慢指针，龟兔赛跑
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

int main()
{
    Solution so;

    return 0;
}