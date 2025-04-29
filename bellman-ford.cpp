#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge
{
    int u, v, w;
};

int main()
{
    int n, m; // número de vértices e arestas
    cin >> n >> m;

    vector<Edge> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int s; // vértice origem
    cin >> s;

    vector<int> dist(n, INT_MAX);
    dist[s] = 0;

    // Relaxa todas as arestas n - 1 vezes
    for (int i = 0; i < n - 1; i++)
    {
        for (const auto &edge : edges)
        {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Verifica ciclo negativo (opcional)
    for (const auto &edge : edges)
    {
        if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.w < dist[edge.v])
        {
            cout << "Ciclo de peso negativo detectado!" << endl;
            return 0;
        }
    }

    cout << "Distancias a partir do vertice " << s << ":\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Vertice " << i << ": ";
        if (dist[i] == INT_MAX)
            cout << "Infinito";
        else
            cout << dist[i];
        cout << endl;
    }

    return 0;
}
