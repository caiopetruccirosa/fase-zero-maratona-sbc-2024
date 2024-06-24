#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pipii pair<int,pair<int,int>>
#define ll long long

using namespace std;

int bfs(vector<vector<int>> &G, int n, int s) {
    vector<bool> visited(n+1, false);
    vector<int> distance(n+1, -1);
    queue<int> q;

    visited[s] = true;
    distance[s] = 0;
    q.push(s);

    int max_distance = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u: G[v]) {
            if (!visited[u]) {
                q.push(u);
                visited[u] = true;
                distance[u] = distance[v]+1;
                max_distance = max(max_distance, distance[u]);
            }
        }
    }

    return max_distance;
}

int main() {_
    int n, m, d;
    cin >> n >> m >> d;

    vector<vector<int>> G(n+1, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    int max_distance = 0;
    for (int i = 1; i <= n; i++)
        max_distance = max(max_distance, bfs(G, n, i));

    int casas_e_estradas = max(0, (2*d - max_distance + 1));
    cout << casas_e_estradas << ' ' << casas_e_estradas << '\n';
    return 0;
}