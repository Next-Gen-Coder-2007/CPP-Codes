#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>> G, int start, int n) {
    queue<int> q;
    vector<int> visited(n, 0);

    visited[start] = 1;
    q.push(start);

    while(!q.empty()){
        int i = q.front();
        q.pop();
        cout << i << " ";
        for(int j = 0; j < n; j++){
            if(G[i][j] == 1 && visited[j] == 0){
                visited[j] = 1;
                q.push(j);
            }
        }
    }
}

void DFS(vector<vector<int>> G, int start, int n, vector<int>& visited) {
    visited[start] = 1;
    cout << start << " ";

    for (int j = 0; j < n; j++) {
        if (G[start][j] == 1 && visited[j] == 0) {
            DFS(G, j, n, visited);
        }
    }
}

int main() {
    vector<vector<int>> G = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int n = 5;
    int start = 0;

    cout << "BFS Traversal: ";
    BFS(G, start, n);

    cout << endl;

    cout << "DFS Traversal: ";
    vector<int> visited(n, 0);
    DFS(G, start, n, visited);

    return 0;
}