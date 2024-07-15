// 移除元素
#include <vector>
#include <algorithm>
#include <iostream>
#include<string>
#include<stack>
#include<unordered_set>
#include<queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    void print(vector<int> nums){
        for (auto item : nums){
            cout << item << " ";
        }
        cout << endl;
    }
    vector<vector<int>> printLevelOrder(TreeNode* root){
        vector<vector<int>> ans;
        if(!root) 
            return {};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> path;
            int n = q.size();
            while(n--){
                root = q.front();
                path.push_back(root->val);
                q.pop();
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            ans.push_back(path);
        }
        return ans;
    }
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(nums,0,nums.size()-1);
    }
    TreeNode* BST(vector<int>& nums,int start,int end){
        if(start>end)
            return nullptr;
        int mid = (start+end)/2;
        TreeNode* node = new TreeNode;
        node->val = nums[mid];
        node->left=BST(nums,start,mid-1);
        node->right=BST(nums,mid+1,end);
        return node;
    }
};

int main()
{
    Solution so;
    vector<int> vec = {-10,-3,0,5,9};
    TreeNode* root = so.sortedArrayToBST(vec);
    so.printLevelOrder(root);
    return 0;
}