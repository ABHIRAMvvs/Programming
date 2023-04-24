#include <bits/stdc++.h>
using namespace std;
#define v 6
int minkey(int key[], bool mstset[]){
    int min = INT_MIN, min_index;
    for(int i=0; i<v;i++){
        if(mstset[i] == false && key[i]<min){
            min = key[i], min_index = i;
        }
    }
    return min_index;
}
void printmst(int parent[],int graph[v][v]){
    for(int i=1; i<v;i++){
        cout << parent[i]<<"-"<<i<<"\t"<<graph[i][parent[i]]<<"\n";
    }
}
void MST(int graph[v][v]){
    int parent[v];
    int key[v];
    bool mstset[v];
    for(int i=0; i<v;i++){
        key[i]= INT_MAX, mstset[i]= false;
    }
    key[0]=0;
    parent[0]=-1;
    for(int count =0; count<v-1; count++){
        int u = minkey(key,mstset);
        mstset[u]=true;
        for(int i=0; i<v;i++){
            if(graph[u][i] & mstset[i]==false && graph[u][i]<key[u]){
                parent[i] = u, key[i] = graph[u][i];
            }
        }
    }
    printmst(parent, graph);
}   
int main(){
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    MST(graph);
    return 0;
}
