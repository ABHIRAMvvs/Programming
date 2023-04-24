#include <iostream>
#include <vector>

using namespace std;

// Function to check if a request can be granted without putting the system into an unsafe state
bool banker_algorithm(vector<vector<int>>& need, vector<vector<int>>& allocation, vector<int>& available, int process, vector<int>& request) {
    // Check if the request is within the process's need
    for (int i = 0; i < 3; i++) {
        if (request[i] > need[process][i]) {
            return false;
        }
    }

    // Check if the request can be granted
    for (int i = 0; i < 3; i++) {
        if (request[i] > available[i]) {
            return false;
        }
    }

    // Temporarily allocate the resources to the process
    for (int i = 0; i < 3; i++) {
        available[i] -= request[i];
        allocation[process][i] += request[i];
        need[process][i] -= request[i];
    }

    // Check if the new state is safe
    vector<bool> finish(3, false);
    for (int i = 0; i < 3; i++) {
        if (finish[i]) {
            continue;
        }

        bool can_be_allocated = true;
        for (int j = 0; j < 3; j++) {
            if (need[i][j] > available[j]) {
                can_be_allocated = false;
                break;
            }
        }

        if (can_be_allocated) {
            for (int j = 0; j < 3; j++) {
                available[j] += allocation[i][j];
            }
            finish[i] = true;
            i = -1;
        }
    }

    // Revert back to the old state if the new state is not safe
    for (int i = 0; i < 3; i++) {
        if (!finish[i]) {
            for (int j = 0; j < 3; j++) {
                available[j] += request[j];
                allocation[process][j] -= request[j];
                need[process][j] += request[j];
            }
            return false;
        }
    }

    // If the new state is safe, the request can be granted
    return true;
}

int main() {
    vector<vector<int>> maximum = {{3, 2, 2}, {1, 2, 4}, {2, 2, 3}};
    vector<vector<int>> allocation = {{1, 1, 1}, {1, 0, 2}, {0, 1, 2}};
    vector<int> available = {10, 10, 10};
    vector<vector<int>> need(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    vector<int> request = {2, 1, 2};
    int process = 3;

    if (banker_algorithm(need, allocation, available, process, request)) {
        cout << "The request can be granted." << endl;
    } else {
        cout << "The request cannot be granted." << endl;
    }

    return 0;
}
