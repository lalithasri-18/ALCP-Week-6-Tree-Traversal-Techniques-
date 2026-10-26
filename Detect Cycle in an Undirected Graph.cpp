#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100];
bool visited[100];

bool dfs(int v, int parent) {
    visited[v] = true;

    for (int i = 0; i < adj[v].size(); i++) {
        int u = adj[v][i];

        if (!visited[u]) {
            if (dfs(u, v))
                return true;
        }
        else if (u != parent) {
            return true;
        }
    }

    return false;
}

int main() {
    int n, m, u, v;
    bool cycle = false;

    cout << "Vertices and edges: ";
    cin >> n >> m;

    cout << "Enter edges:\n";

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                cycle = true;
                break;
            }
        }
    }

    if (cycle)
        cout << "Cycle Found";
    else
        cout << "No Cycle";

    return 0;
}
