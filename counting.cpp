#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n+1];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans[n+1];
    ans[0] = 1;
    for(int i=1;i<n;i++){
        ans[i] = 1;
        for(int j=i-1;j>=0;j--){
            if(a[j]<=a[i]){
                ans[i]++;
            }
            else{
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
