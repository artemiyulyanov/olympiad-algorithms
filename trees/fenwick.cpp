#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>

struct FenwickTree {
    int n;
    std::vector<int> t;

    FenwickTree(const int n): n(n), t(n, 0) {}

    void init(std::vector<int> &arr) {
        for (int i = 0; i < n; i++) {
            modify(i, arr[i]);
        }
    }

    void modify(int i, int d) {
        while (i < n) {
            t[i] += d;
            i = i | (i + 1);
        }
    }

    int prefix_sum(int i) {
        int sum = 0;

        while (i >= 0) {
            sum += t[i];
            i = (i & (i + 1)) - 1;
        }

        return sum;
    }
};

int main() {
    int n, l, r;
    std::cin >> n >> l >> r;

    std::cin.ignore();

    std::string numbers_string;
    std::getline(std::cin, numbers_string);

    std::vector<int> numbers{};

    std::stringstream ss(numbers_string);
    int num;

    while (ss >> num) {
        numbers.push_back(num);
    }

    FenwickTree tree(n);
    tree.init(numbers);

    std::cout << tree.prefix_sum(r) - tree.prefix_sum(l) << std::endl;

    return 0;
}