#include<iostream>
using namespace std;
int main(){
    int n, p, i, j, smallest, temp;
    cout<<"Enter the number of memory blocks: ";
    cin>>n;
    int memory[n];
    for(i=0;i<n;i++){
        cout<<"Enter size of block "<<i<<": ";
        cin>>memory[i];
    }
    cout<<"Enter the number of processes: ";
    cin>>p;
    int process[p];
    for(i=0;i<p;i++){
        cout<<"Enter size of process "<<i<<": ";
        cin>>process[i];
    }
    for(i=0;i<p;i++){
        smallest = -1;
        for(j=0;j<n;j++){
            if(memory[j]>=process[i]){
                if(smallest == -1){
                    smallest = j;
                }
                else if(memory[j]<memory[smallest]){
                    smallest = j;
                }
            }
        }
        if(smallest != -1){
            cout<<"The Process "<<i<<" allocated to "<<memory[smallest]<<endl;
            memory[smallest] -= process[i];
        }
        else{
            cout<<"The Process "<<i<<" can't be allocated"<<endl;
        }
    }
    return 0;
}
