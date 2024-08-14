#include<iostream>
#include<vector>
using namespace std;


void print(vector<int>& nums){
    for(auto num:nums){
        cout<<num<<" ";
    }
    cout<<endl;
}
void insertion(vector<int>& nums){
    int n=nums.size();
    for(int i=1;i<n;++i){
        int base = nums[i],j=i-1;
        while(j>=0 && nums[j]>base){
            nums[j+1]=nums[j];
            j--;
        }
        nums[j+1]=base;
    }
}


int main(){
    vector<int> vec = {4,1,3,1,5,2};
    print(vec);
    insertion(vec);
    print(vec);
    return 0;
}