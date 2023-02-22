#include<bits/stdc++.h>
using namespace std;

class Activity{
public:
    int id;
    int start;
    int finish;
};

void sortFinishTimes(Activity arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i].finish>arr[j].finish) swap(arr[i],arr[j]);
        }
    }
}

void selectMaxActivities(Activity arr[],int n){
    sortFinishTimes(arr,n);
    int i=0;
    cout<<arr[i].id<<" ";
    for(int j=1;j<n;j++){
        if(arr[j].start>=arr[i].finish){
            cout<<arr[j].id<<" ";
            i=j;
        }
    }
}