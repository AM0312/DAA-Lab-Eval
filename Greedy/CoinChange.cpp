// Time- O(amt)

#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int> denoms,int amt){
    sort(denoms.begin(),denoms.end());
    int n=denoms.size();
    int count=0;
    for(int i=n-1;i>=0;i--){
        while(amt>=denoms[i]){
            count++;
            amt-=denoms[i];
        }
    }
    return count;
}