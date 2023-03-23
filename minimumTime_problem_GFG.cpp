
#include <iostream>
using namespace std;
int minimumTime(int n, int cur, vector<int> &pos, vector<int> &time){
    int ans[n];
    for(int i=0; i<n;i++){
        if(pos[i]<cur){
            ans[i]= (cur-pos[i])*time[i];
        }
        else{
            ans[i]= (pos[i]-cur)*time[i];
        }
    }
    int min = ans[0];
    for(int i=0; i<n;i++){
        if(a[i]<min){
            min = a[i];
        }
    }
    return min;
}