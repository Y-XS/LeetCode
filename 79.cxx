// 移除元素
#include <vector>
#include <algorithm>
#include <iostream>
#include<string>
#include<stack>
#include<unordered_set>
#include<unordered_map>

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
    void print(string s)
    {
        cout << s << endl;
    }


    bool ans = false;
    int row,col;
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0)
            return true;
        row = board.size();
        col = board[0].size();
        vector<vector<bool>> selected(row,vector<bool>(col, false));
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(board[i][j] != word[0])
                    continue;
                if(dfs(0,i,j,board,selected,word))
                    return true;
            }
        }
        return false;
    }
    bool dfs(int idx,int x,int y,const vector<vector<char>>& board,vector<vector<bool>>& selected,const string& word){
        if(idx == word.size())
            return true;
        if(x<0 || x>= row || y<0 || y>=col || selected[x][y])
            return false;
        if(board[x][y]==word[idx]){
            selected[x][y] = true;
            bool ret = dfs(idx+1,x,y-1,board,selected,word) ||
            dfs(idx+1,x,y+1,board,selected,word) ||
            dfs(idx+1,x-1,y,board,selected,word) ||
            dfs(idx+1,x+1,y,board,selected,word);
            selected[x][y] = false;
            return ret;
        }
        return false;
    }
};

int main()
{
    Solution so;
    vector<vector<char>> board={
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'},
    };
    string word = "ABCCED";
    bool ans = so.exist(board,word);
    cout<<"ans = "<< ans<<endl;


    return 0;
}