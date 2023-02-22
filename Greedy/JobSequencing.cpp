#include<bits/stdc++.h>
using namespace std;

class Job{
public:
    int id;
    int deadline;
    int profit;
};

void sortOnProfits(Job arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i].profit>arr[j].profit) swap(arr[i],arr[j]);
        }
    }
    reverse(arr,arr+n);
}

void sequenceJobs(Job arr[],int n){
    sortOnProfits(arr,n);
    int sequence[n];
    bool availableSlots[n]={false};

    for(int i=0;i<n;i++){
        for(int j=min(n,arr[i].deadline)-1;j>=0;j--){
            if(!availableSlots[j]){
                sequence[j]=arr[i].id;
                availableSlots[j]=true;
                break;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(availableSlots[i]) cout<<sequence[i]<<" ";
    }
}