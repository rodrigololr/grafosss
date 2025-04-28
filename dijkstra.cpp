#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(vector<vector<pii>>& adj, int s, vector<int>& dist, vector<int>& prev) {
    int n = adj.size();
    dist.assign(n, INT_MAX); // dist[v] = ∞
    prev.assign(n, -1);      // prev[v] = -1

    dist[s] = 0;             // dist[s] = 0

    // H = fila-prioridade-min(V, dist)
    priority_queue<pii, vector<pii>, greater<pii>> H;
    for (int v = 0; v < n; v++) {
        H.push({dist[v], v});
    }

    while (!H.empty()) { // enquanto a fila não estiver vazia
        int u = H.top().second; // u = H.front() (menor dist)
        H.pop(); // remove

        for (auto edge : adj[u]) { // para todo v em N(u)
            int v = edge.first;
            int w_uv = edge.second;

            if (dist[v] > dist[u] + w_uv) { // dist[v] > dist[u] + w(u,v)
                dist[v] = dist[u] + w_uv;
                prev[v] = u;
                H.push({dist[v], v}); // H.increase-priority(v, dist[v])
            }
        }
    }   
}

int main() {
    int n, m;
    cin >> n >> m; // número de vértices e arestas

    vector<vector<pii>> adj(n); // lista de adjacência

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        //adj[v].push_back({u, w}); // se for grafo não-direcionado
    }

    vector<int> dist, prev;
    int s;
    cin >> s; // vértice origem

    dijkstra(adj, s, dist, prev);

    cout << "Distancias a partir do vertice " << s << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Vertice " << i << ": ";
        if (dist[i] == INT_MAX) cout << "Infinito";
        else cout << dist[i];
        cout << endl;
    }

    return 0;
}
