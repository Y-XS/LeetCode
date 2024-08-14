// 移除元素
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <thread>
#include <chrono>

using namespace std;

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
    void print(vector<bool> vec)
    {
        for (auto item : vec)
        {
            cout << item << " ";
        }
        cout << endl;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<char,int> map;
        int n = strs.size();

        for (int i=0;i<n ;++i)
        {
            for(auto c:strs[i]){
                map[c]++;
            }
            for(int j=i+1;j<n;++j){
                for(auto c:strs[j]){
                    if(map.count(c)==0)
                        break;
                }
                
            }
        }

        return ans;
    }
};

int main()
{
    Solution so;

    return 0;
}