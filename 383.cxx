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

    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> map;
        for(auto c:magazine){
            map[c]++;
        }
        for(auto c: ransomNote){
            if(map[c] == 0)
                return false;
            map[c]--;
        }
        return true;
    }
};

int main()
{
    Solution so;
    string ransomNote = "aa";
    string magazine = "aba";
    cout<<so.canConstruct(ransomNote,magazine);
    return 0;
}