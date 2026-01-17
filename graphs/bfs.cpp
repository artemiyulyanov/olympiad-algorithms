#include <iostream>
#include <cmath>
#include <deque>
#include <set>
#include <sstream>
#include <vector>

std::vector<int> bfs(int n, std::vector<std::vector<int>> &adj_list, int start) {
    std::vector<int> distances(n+1, INT_MAX);
    std::deque<int> queue{};

    distances[start] = 0;

    queue.push_back(start);

    while (!queue.empty()) {
        auto node = queue.front();
        queue.pop_front();

        for (int u : adj_list[node]) {
            if (distances[u] == INT_MAX) {
                distances[u] = distances[node] + 1;
                queue.push_back(u);
            }
        }
    }

    return distances;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<std::vector<int>> adj_list(n+1, std::vector<int>()); // 1-based

    for (int i = 0; i < m; i++) {
        std::string road_str;
        getline(std::cin, road_str);

        std::stringstream ss(road_str);
        int num;

        std::vector<int> road(0);

        while (ss >> num) {
            road.push_back(num);
        }

        adj_list[road[0]].push_back(road[1]);
        adj_list[road[1]].push_back(road[0]);
    }

    std::vector<int> nodes = bfs(n, adj_list, 1);
    auto it = nodes.begin()+1;

    for (int i = 1; it != nodes.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}