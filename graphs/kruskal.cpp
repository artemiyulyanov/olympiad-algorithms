#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>

struct DisjointSet {
    int n;
    std::vector<int> parents; // 1-based
    std::vector<int> ranks; // 1-based

    DisjointSet(int n) : n(n), parents(n+1), ranks(n+1, 0) {
        std::iota(std::begin(parents), std::end(parents), 0);
    }

    int get(int x) {
        if (parents[x] != x) {
            parents[x] = get(parents[x]);
        }

        return parents[x];
    }

    void unite(int x, int y) {
        x = get(x);
        y = get(y);

        if (x == y) return;
        if (ranks[x] == ranks[y]) ranks[x]++;

        if (ranks[x] < ranks[y]) {
            parents[x] = y;
        } else if (ranks[x] > ranks[y]) {
            parents[y] = x;
        } else {
            parents[y] = x;
            ranks[x]++;
        }
    }
};

std::vector<std::vector<int>> kruskalFindMST(DisjointSet &disjoint_set, const std::vector<std::vector<int>> &edges) {
    std::vector<std::vector<int>> mst_edges{};

    for (std::vector<int> edge : edges) {
        int u = edge[0], v = edge[1];

        if (disjoint_set.get(u) != disjoint_set.get(v)) {
            mst_edges.push_back(edge);
            disjoint_set.unite(u, v);
        }

        if (mst_edges.size() == disjoint_set.n-1) {
            return mst_edges;
        }
    }

    return mst_edges;
}

int main() {
    int v, e;
    std::cin >> v >> e;

    std::vector<std::vector<int>> edges(e, std::vector<int>());

    for (int i = 0; i < e; i++) {
        int x, y, weight;

        std::cin >> x >> y >> weight;

        edges[i].push_back(x);
        edges[i].push_back(y);
        edges[i].push_back(weight);
    }

    std::sort(edges.begin(), edges.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
        return a[2] < b[2];
    });

    auto* disjoint_set = new DisjointSet(static_cast<int>(edges.size()));
    std::vector<std::vector<int>> mst_edges = kruskalFindMST(*disjoint_set, edges);

    delete disjoint_set;

    for (std::vector<int> edge : mst_edges) {
        std::cout << edge[0] << ' ' << edge[1] << ' ' << edge[2] << std::endl;
    }

    return 0;
}