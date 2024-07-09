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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        ListNode* p = head;
        while(p){
            if(set.count(p)!=0)
                return p;
            set.insert(p);
            p = p->next;
        }
        return nullptr;
    }
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        ListNode* p = head;
        while(p){
            if(set.count(p)!=0)
                return true;
            set.insert(p);
            p=p->next;
        }
        return false;
    }
};

int main()
{
    Solution so;

    return 0;
}