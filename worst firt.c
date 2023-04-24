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
    int process[p];
    for(i=0;i<p;i++){
        cout<<"Enter size of process "<<i+1<<": ";
        cin>>process[i];
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
            cout<<"File "<<i+1<<": "<<process[i]<<" | Block "<<largest+1<<": "<<memory[largest]<<" | Fragment: "<<memory[largest]-process[i]<<endl;
            memory[largest] -= process[i];
        }
        else{
            cout<<"File "<<i+1<<": "<<process[i]<<" can't be allocated"<<endl;
        }
    }
    return 0;
}
