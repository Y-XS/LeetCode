#include<iostream>
#include<vector>
using namespace std;


void print(vector<int>& nums){
    for(auto num:nums){
        cout<<num<<" ";
    }
    cout<<endl;
}
void selection(vector<int>& nums){
    int n=nums.size();
    for(int i=0;i<n;++i){
        // 记录最小值索引
        int k = i;
        for(int j=i+1;j<n;++j){
            if(nums[j]<nums[k]) 
                k = j;
        }
        // 交换最小值
        std::swap(nums[i],nums[k]);
    }
}


int main(){
    vector<int> vec = {4,1,3,1,5,2};
    print(vec);
    selection(vec);
    print(vec);
    return 0;
}