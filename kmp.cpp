#include <iostream>
#include <ranges>
#include <vector>
#include <bits/parse_numbers.h>

std::vector<int> prefixFunction(const std::string &line) {
    std::vector<int> prefix(static_cast<int>(line.length()), 0);

    for (int i = 1; i < line.length(); i++) {
        int k = prefix[i - 1];

        while (k > 0 && line[i] != line[k]) {
            k = prefix[k - 1];
        }

        if (line[i] == line[k]) {
            k++;
        }

        prefix[i] = k;
    }

    return prefix;
}

std::vector<int> kmpAlgorithm(const std::string &line, const std::string &pattern) {
    std::string s = pattern + "#" + line;
    const std::vector<int> prefix = prefixFunction(s);

    const int pl = static_cast<int>(pattern.length());
    std::vector<int> result{};

    for (int i = 0; i < line.length(); i++) {
        if (prefix[i + pl + 1] == pl) {
            result.push_back(i - pl);
        }
    }

    return result;
}

int main() {
    std::string line;
    std::string pattern;

    std::getline(std::cin, line);
    std::cin.ignore();
    std::getline(std::cin, pattern);

    std::vector<int> result = kmpAlgorithm(line, pattern);

    for (int i : result) {
        std::cout << i << std::endl;
    }

    return 0;
}