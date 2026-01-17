#include <iostream>
#include <math.h>
#include <set>
#include <sstream>
#include <vector>

std::set<int> dfs(std::vector<std::vector<int>> &adj_list, int start, std::set<int>* visited = nullptr) {
    if (visited == nullptr) {
        visited = new std::set<int>();
    }

    visited->insert(start);

    for (int neighbor : adj_list[start]) {
        if (visited->find(neighbor) == visited->end()) {
            dfs(adj_list, neighbor, visited);
        }
    }

    return *visited;
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<std::vector<int>> adj_list(n+1, std::vector<int>()); // 1-based

    for (int i = 0; i < n - 1; i++) {
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

    std::set<int> nodes = dfs(adj_list, 1);
    auto it = nodes.begin();

    for (int i = 0; it != nodes.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}