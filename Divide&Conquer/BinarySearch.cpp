#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr,int s,int e,int key){
    if(s>e) return -1;
    int mid=(s+e)/2;
    if(arr[mid]==key) return mid;
    else if(arr[mid]>key) return binarySearch(arr,s,mid-1,key);
    else return binarySearch(arr,mid+1,e,key); 
}

// int main(){
//     vector<int> arr{1,5,8,15,34,55,78};
//     cout<<binarySearch(arr,0,arr.size()-1,55);
// }