#include <iostream>
#include <vector>

struct Edge {
    int to, weight;

    Edge(const int to, const int weight) : to(to), weight(weight) {}
};

std::vector<int> dijkstra(const int vertices, const int start, const std::vector<std::vector<Edge>> &edges) {
    std::vector<int> distances(vertices+1, INT_MAX);
    std::vector<bool> visited(vertices+1, false);

    distances[start] = 0;

    for (int i = 0; i < vertices; i++) {
        int v = -1;

        for (int j = 1; j <= vertices; j++) {
            if (!visited[j] && (v == -1 || distances[j] < distances[v])) {
                v = j;
            }
        }

        if (distances[v] == INT_MAX) {
            break;
        }

        visited[v] = true;
        for (Edge edge : edges[v]) {
            if (distances[v] + edge.weight < distances[edge.to]) {
                distances[edge.to] = distances[v] + edge.weight;
            }
        }
    }

    return distances;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<Edge>> edges(n+1, std::vector<Edge>());

    for (int i = 0; i < m; i++) {
        int u, v, weight;

        std::cin >> u >> v >> weight;
        edges[u].emplace_back(v, weight);
    }

    std::vector<int> res = dijkstra(n, 1, edges);

    for (int i = 1; i <= n; i++) {
        std::cout << i << ": " << res[i] << std::endl;
    }

    return 0;
}