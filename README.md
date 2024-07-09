# Tips

+ 回文数用栈或者双指针
+ 链表头最好单独分配空间，head->next再指向第一个元素，返回head->next即可



# 常用方法

## 双指针

## 快慢指针

## 哈希表



# 经典例题

## T 228 
双指针注意下表边界，用 i-1

```c++
//nums[i - 1] + 1
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int i = 0;
        int n = nums.size();
        while (i < n) {
            int low = i;
            i++;
            while (i < n && nums[i] == nums[i - 1] + 1) {
                i++;
            }
            int high = i - 1;
            string temp = to_string(nums[low]);
            if (low < high) {
                temp.append("->");
                temp.append(to_string(nums[high]));
            }
            ret.push_back(move(temp));
        }
        return ret;
    }
};
```

## T 71

简化路径

```c++
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
```

## T 206 反转链表

## T 21 合并链表

```c++
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //head单独分配空间，head->next再指向第一个元素，否则需要单独判断head
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
```





