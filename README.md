# Tips

+ 注意边界条件

+ 回文数用栈或者双指针

+ 链表头最好单独分配空间，head->next再指向第一个元素，返回head->next即可

+ 初始化二维数组时，注意指定数组大小

  ```c++
  vector<vector<int>> dp(n, vector<int>(m));
  ```
  
  ```c++
  //此题杨辉三角，数组大小不固定，需要显示指定
  vector<vector<int>> generate(int numRows) {
      if(numRows==0)
          return {{}};
      vector<vector<int>> ans(numRows);//注意此处
      for(int i=0;i<numRows;++i){
          ans[i].resize(i+1);;		//注意此处
          for(int j=0;j<=i;++j){
              if(j==0||j==i){
                  ans[i][j]=1;
                  continue;
              }
              ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
          }
      }
      return ans;
  }
  ```
  
  



# 数据结构

## 树

### 二叉搜索树

定义：

+ 节点左子树只包含 **小于** 当前节点的数
+ 节点的右子树只包含 **大于** 当前节点的数
+ 所有左子树和右子树自身必须也是二叉搜索树

# 常用方法

## 双指针

## 快慢指针

## 哈希表



## 回溯

> 回溯思路：https://www.bilibili.com/video/BV1mG4y1A7Gu/?vd_source=39470039eed280e7cb9ce02e946c495b

```c++
//78题
vector<vector<int>> ans;
vector<int> tmp;
vector<vector<int>> subsets(vector<int>& nums) {
    if(nums.size()==0)
        return ans;
    backtrack(0,nums);
    return ans;
}
void backtrack(int idx,const vector<int> &nums){
    //判断边界条件
    if(nums.size() == idx){
        ans.push_back(tmp);
        return;
    }
    //不选
    backtrack(idx+1,nums);
    //选择
    tmp.push_back(nums[idx]);
    backtrack(idx+1,nums);
    tmp.pop_back();
}
```

## 动态规划

```c++
//70题 爬楼梯
int climbStairs(int n) {
    if(n==1||n==2)
        return n;
    int a=1,b=2;
    for(int i=3;i<=n;++i){
        int tmp=b;
        b=a+b;
        a= tmp;
    }
    return b;
}
int climbStairs(int n) {
    int p = 0, q = 0, r = 1;
    for (int i = 1; i <= n; ++i) {
        p = q; 
        q = r; 
        r = p + q;
    }
    return r;
}
```

```c++
//198 打家劫舍
int rob(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    int size = nums.size();
    if (size == 1) {
        return nums[0];
    }
    int first = nums[0], second = max(nums[0], nums[1]);
    for (int i = 2; i < size; i++) {
        int temp = second;
        second = max(first + nums[i], second);
        first = temp;
    }
    return second;
}
```





# 二叉树

二叉树构造：

```c++
//必须由两种遍历数组构造
TreeNode* makeTree(vector<int>& preorder, vector<int>& inorder){
    if(inorder.size() == 0 || preorder.size() == 0)
        return nullptr;
    TreeNode* root = new TreeNode;
    root->val = preorder[0];
    int splitPoint = 0;
    for(int i=0;i<inorder.size();++i){
        if(inorder[i] == root->val){
            splitPoint = i;
            break;
        }
    }
    vector<int> inleft(inorder.begin(),inorder.begin()+splitPoint);
    vector<int> inright(inorder.begin()+splitPoint+1,inorder.end());
    vector<int> preleft(preorder.begin()+1,preorder.begin()+splitPoint+1);
    vector<int> preright(preorder.begin()+splitPoint+1,preorder.end());
    root->left = makeTree(preleft,inleft);
    root->right = makeTree(preright,inright);
    return root;
}
```

+ 先序遍历
+ 中序遍历
+ 后序遍历
+ 层序遍历
+ 递归
+ 迭代

深度优先DFS

```c++
//知道左右子树最大深度l，r，则该二叉树最大深度为 max(l,r)+1
int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
```

广度优先BFS

```c++
int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    queue<TreeNode*> Q;
    Q.push(root);
    int ans = 0;
    while (!Q.empty()) {
        int sz = Q.size();
        while (sz > 0) {
            TreeNode* node = Q.front();Q.pop();
            if (node->left) Q.push(node->left);
            if (node->right) Q.push(node->right);
            sz -= 1;
        }
        ans += 1;
    } 
    return ans;
}
```





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





