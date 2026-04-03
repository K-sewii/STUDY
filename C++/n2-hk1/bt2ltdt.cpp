#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
using pii = pair<int, int>;

vector<int> dijkstra(int n, int start, vector<vector<pii>>& adj, vector<int>& pre) {
    vector<int> dist(n + 1, INF);
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u])
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pre[v] = u;
                pq.push({dist[v], v});
            }
    }
    return dist;
}

int main() {
    int n, m, s, t, x;
    cin >> n >> m >> s >> t >> x;
    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> pre1(n + 1, -1), pre2(n + 1, -1);
    auto dist1 = dijkstra(n, s, adj, pre1);
    auto dist2 = dijkstra(n, x, adj, pre2);

    int total = dist1[x] + dist2[t];
    vector<int> path1, path2;

    for (int v = x; v != -1; v = pre1[v]) path1.push_back(v);
    reverse(path1.begin(), path1.end());

    for (int v = t; v != x; v = pre2[v]) path2.push_back(v);

    vector<int> full = path1;
    full.insert(full.end(), path2.begin(), path2.end());

    cout << full.size() << " " << total << "\n";
    for (int v : full) cout << v << " ";
}
