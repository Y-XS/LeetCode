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


    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> set;
        ListNode *p = headA;
        ListNode *q = headB;
        while(p){
            set.insert(p);
            p = p->next;
        }
        while(q){
            if(set.count(q)!=0){
                return q;
            }
            q = q->next;
        }
        return nullptr;
    }
};

int main()
{
    Solution so;
    // vector<int> nums = {0,1,0,3,12};
    return 0;
}