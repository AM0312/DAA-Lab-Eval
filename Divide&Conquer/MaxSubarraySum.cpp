#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> arr,int s,int e){
    if(s>=e) return arr[s];
    int pivot=(s+e)/2;
    int left,right;
    left=right=INT_MIN;
    int sum=0;
    for(int i=pivot;i>=s;i--){
        sum+=arr[i];
        left=max(sum,left);
    }
    sum=0;
    for(int i=pivot+1;i<=e;i++){
        sum+=arr[i];
        right=max(sum,right);
    }
    return max(max(maxSubarraySum(arr,s,pivot),maxSubarraySum(arr,pivot+1,e)),left+right);
}

// int main(){
//     vector<int> arr{-2,1,-3,4,-1,2,1,-5,4};
//     cout<<maxSubarraySum(arr,0,arr.size()-1)<<endl;
// }