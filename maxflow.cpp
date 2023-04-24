#include<bits/stdc++.h>
using namespace std;

// Number of nodes in the network
#define V 6 

// Function to find the maximum flow between source and sink using Ford-Fulkerson algorithm
int fordFulkerson(int graph[V][V], int source, int sink) {

    int u, v;
    int residualGraph[V][V];

    // Initialize residual graph as the original graph
    for (u = 0; u < V; u++) {
        for (v = 0; v < V; v++) {
            residualGraph[u][v] = graph[u][v];
        }
    }

    int parent[V];
    int maxFlow = 0;

    // Loop until there is a path from source to sink in residual graph
    while (bfs(residualGraph, source, sink, parent)) {

        // Find the minimum capacity of the edges along the path
        int pathFlow = INT_MAX;
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        // Update the residual capacities of the edges and reverse edges
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        // Add path flow to overall flow
        maxFlow += pathFlow;
    }

    return maxFlow;
}

// Function to find if there is a path from source to sink in residual graph using BFS algorithm
bool bfs(int residualGraph[V][V], int source, int sink, int parent[]) {

    bool visited[V];
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    // Standard BFS Loop
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (visited[v] == false && residualGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // If we can reach sink in BFS starting from source, then return true, else false
    return (visited[sink] == true);
}

int main() {

    int graph[V][V];

    // Input the number of edges in the network
    int numEdges;
    cout << "Enter the number of edges in the network: ";
    cin >> numEdges;

    // Initialize graph with all edges having zero capacity
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    // Input the edges and their capacities
    int src, dest, cap;
    for (int i = 0; i < numEdges; i++) {
        cout << "Enter the source vertex: ";
        cin >> src;
        cout << "Enter the destination vertex: ";
        cin >> dest;
        cout << "Enter the capacity of "<<src<<"-"<<dest<<" edge: ";
        cin >> cap;
        graph[src][dest] = cap;
    }
    for(int i=0; i<V;i++){
        for(int j=0; j<V; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

    // Find the maximum flow between source and sink using Ford-Fulkerson algorithm
    int maxFlow = fordFulkerson(graph, 0, 5);
    cout << "MAx flow is "<< maxFlow;
}

   
