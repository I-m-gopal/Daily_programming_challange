//Find the Shortest Path in an Unweighted Graph
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int shortestPath(int V, vector<vector<int>>& edges, int start, int end) {
    vector<vector<int>> adjList(V);
    for (auto& edge : edges) {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }
    
    queue<pair<int, int>> q;
    vector<bool> visited(V, false);
    
    q.push({start, 0});
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if (node == end) return dist;
        
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, dist + 1});
            }
        }
    }
    
    return -1;
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};
    int start = 0, end = 4;
    cout << "Shortest path from " << start << " to " << end << " is: " 
         << shortestPath(V, edges, start, end) << endl;
    return 0;
}
