#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> g[N];
bool vis[N];

void dfs(int vertex) {

    // take action on vertex after entering
    vis[vertex] = true;
    cout << vertex << " ";

    for(int child : g[vertex]) {

        if(vis[child])
            continue;

        // take action on child before entering child
        dfs(child);

        // take action on child after exiting child
    }

    // take action on vertex before exiting vertex
}

int main() {

    int n, m;
    cin >> n >> m;

    // n = number of vertices
    // m = number of edges

    for(int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;

        // undirected graph
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int start;
    cin >> start;

    dfs(start);

    return 0;
}
