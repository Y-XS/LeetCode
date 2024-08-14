#include<iostream>
#include<vector>
using namespace std;


void print(vector<int>& nums){
    for(auto num:nums){
        cout<<num<<" ";
    }
    cout<<endl;
}
void bubble(vector<int>& nums){
    // 减1是不用与自己比较
    int n=nums.size()-1;
    for(int i=0;i<n;++i){
        //flag用于检测是否有序
        int flag=0;
        for(int j=0;j<n-i;++j){
            if(nums[j]>nums[j+1]){
                std::swap(nums[j],nums[j+1]);
                flag=1;
            }
        }
        // 如果某一趟没有交换位置，则说明已经排好顺序，直接退出
        if(flag==0)
            break;
    }
}


int main(){
    vector<int> vec = {4,1,3,1,5,2};
    print(vec);
    bubble(vec);
    print(vec);
    return 0;
}