#include<bits/stdc++.h>
using namespace std;

class Item{
public:
    int value;
    int weight;
};

void sortOnRatios(Item arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            float r1=arr[i].value/arr[i].weight;
            float r2=arr[j].value/arr[j].weight;
            if(r1>r2) swap(arr[i],arr[j]);
        }
    }
    reverse(arr,arr+n);
}

float fractionalKnapsack(int w,Item arr[],int n){
    sortOnRatios(arr,n);
    float res=0;
    for(int i=0;i<n;i++){
        if(arr[i].weight<=w){
            w-=arr[i].weight;
            res+=arr[i].value;
        }
        else{
            res+=arr[i].value*(float(w)/float(arr[i].weight));
            break;
        }
    }
    return res;
}