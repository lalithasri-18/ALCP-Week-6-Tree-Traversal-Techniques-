#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100];
bool visited[100];

void dfs(int v) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < adj[v].size(); i++) {
        int u = adj[v][i];

        if (!visited[u])
            dfs(u);
    }
}

void bfs(int start) {
    bool vis[100] = {false};
    queue<int> q;

    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        cout << v << " ";

        for (int i = 0; i < adj[v].size(); i++) {
            int u = adj[v][i];

            if (!vis[u]) {
                vis[u] = true;
                q.push(u);
            }
        }
    }
}

int main() {
    int n, m, u, v, start;

    cout << "Vertices and edges: ";
    cin >> n >> m;

    cout << "Enter edges:\n";
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Start vertex: ";
    cin >> start;

    cout << "DFS: ";
    dfs(start);

    cout << "\nBFS: ";
    bfs(start);

    return 0;
}
