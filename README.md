# LeetCode Note

# TS

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

