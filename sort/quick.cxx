#include<iostream>
#include<vector>
using namespace std;


void print(vector<int>& nums){
    for(auto num:nums){
        cout<<num<<" ";
    }
    cout<<endl;
}

int partition(vector<int>& nums,int left,int right){
    int i=left,j=right;
    while(i<j){
        while(i<j && nums[j]>=nums[left])
            --j;
        while(i<j && nums[i]<=nums[left])
            ++i;
        std::swap(nums[i],nums[j]);
    }
    std::swap(nums[i],nums[left]);
    return i;
}
void quick(vector<int>& nums,int left,int right){
    if(left>=right)return;
    int pivot = partition(nums,left,right);
    partition(nums,left,pivot-1);
    partition(nums,pivot+1,right);
}


int main(){
    vector<int> vec = {4,1,3,1,5,2};
    print(vec);
    quick(vec,0,vec.size()-1);
    print(vec);
    return 0;
}