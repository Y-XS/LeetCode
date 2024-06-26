// 移除元素
#include <vector>
#include <algorithm>
#include <iostream>
#include<string>
#include<unordered_map>
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
    void print(string s)
    {
        cout << s << endl;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int start,end;
        vector<vector<int>> retVec;
        unordered_map<int,int> merged;
        start = intervals[0][0];
        end = intervals[0][1];
        for(int i=0;i<n;++i){
            if(merged[i]!=0)
                continue;
            for(int j=i+1;j<n;++j){
                if(merged[j]!=0)
                    continue;
                if(intervals[j][0] > end || intervals[j][1] < start){
                    continue;
                }else{
                    start = min(start,intervals[j][0]);
                    end = max(end,intervals[j][1]);
                    merged[j]++;
                    merged[i]++;
                }
            }
            retVec.push_back({start,end});
        }
        return retVec;
    }
};

int main()
{
    // vector<vector<int>> nums = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> nums = {{1,4},{4,5}};
    // vector<int> nums = {0,2,3,4,6,8,9};
    Solution so;
    vector<vector<int>> ret = so.merge(nums);
    for(auto item:ret){
        for(auto i:item){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}