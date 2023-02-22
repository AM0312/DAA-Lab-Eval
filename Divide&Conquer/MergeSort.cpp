#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int s,int e){
    int i=s;
    int mid=(s+e)/2;
    int j=mid+1;

    vector<int> temp;
    while(i<=mid and j<=e){
        if(arr[i]<arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while(i<=mid) temp.push_back(arr[i++]);
    while(j<=e) temp.push_back(arr[j++]);
    int k=0;
    for(int idx=s;idx<=e;idx++) arr[idx]=temp[k++];
    return;
}

void mergeSort(vector<int> &arr,int s,int e){
    if(s>=e) return;
    int mid=(s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}

int main(){
    vector<int> arr{11,5,2,1,7,6,4};
    mergeSort(arr,0,arr.size()-1);
    for(auto x:arr) cout<<x<<" ";
}