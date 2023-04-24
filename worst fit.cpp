#include<iostream>
using namespace std;
int main(){
    int n, p, i, j, largest, temp;
    cout<<"Enter the number of memory blocks: ";
    cin>>n;
    int memory[n];
    for(i=0;i<n;i++){
        cout<<"Enter size of block "<<i+1<<": ";
        cin>>memory[i];
    }
    cout<<"Enter the number of processes: ";
    cin>>p;
    int process[p], allocation[p], fragmentation[p];
    for(i=0;i<p;i++){
        cout<<"Enter size of process "<<i+1<<": ";
        cin>>process[i];
        allocation[i] = -1;
    }
    for(i=0;i<p;i++){
        largest = -1;
        for(j=0;j<n;j++){
            if(memory[j]>=process[i]){
                if(largest == -1){
                    largest = j;
                }
                else if(memory[j]>memory[largest]){
                    largest = j;
                }
            }
        }
        if(largest != -1){
            allocation[i] = largest;
            fragmentation[i] = memory[largest] - process[i];
            memory[largest] -= process[i];
        }
    }
    cout<<"Block ";
    for(i=0;i<n;i++){
        cout<<i+1<<":";
    }
    cout<<"File ";
    for(i=0;i<p;i++){
        cout<<i+1<<":";
    }
    cout<<endl;
    for(i=0;i<n;i++){
        cout<<memory[i]<<" ";
    }
    cout<<"  ";
    for(i=0;i<p;i++){
        if(allocation[i] == -1){
            cout<<"NA"<<" ";
        }
        else{
            cout<<allocation[i]+1<<" ";
        }
    }
    cout<<endl;
    for(i=0;i<p;i++){
        if(allocation[i] != -1){
            cout<<"File "<<i+1<<" : "<<process[i]<<" : ";
            cout<<"Block "<<allocation[i]+1<<" : "<<memory[allocation[i]]<<" : ";
            cout<<fragmentation[i]<<endl;
        }
    }
    return 0;
}
