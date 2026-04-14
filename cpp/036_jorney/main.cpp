#include <iostream>
#include <vector>
#include <queue>

using Row = std::vector<int>;
using Matrix = std::vector<Row>;

Row createRow(int size) {
    Row result;
    result.resize(size);
    return result;
}

Matrix createMatrix(int size) {
    Matrix result;
    for (int i = 0; i < size; ++i) {
        result.push_back(createRow(size));
    }
    return result;
}

struct Point {
    int x;
    int y;
};

using Towns = std::vector<Point>;

constexpr int Infinity = 9;

int distance(Point lhs, Point rhs) {
    return std::abs(lhs.x - rhs.x) + std::abs(lhs.y - rhs.y);
}

Matrix createGraph(const Towns& towns, int maxLength) {
    const int townsCount = towns.size();
    Matrix result = createMatrix(townsCount);
    for (int i = 0; i < townsCount; ++i) {
        for (int j = i + 1; j < townsCount; ++j) {
            const int len = distance(towns[i], towns[j]);
            const int x = len > maxLength ? Infinity : 1;
            result[i][j] = x;
            result[j][i] = x;
        }
    }
    return result;
}

void print(const Matrix& m) {
    const int size = m.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << m[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

struct Foo {
    int number;
    int distance;
};

int bfs(const Matrix& m, int source, int target) {
    const int size = m.size();
    std::vector<bool> visited;
    visited.resize(size);
    std::queue<Foo> queue;
    queue.push({source, 0});
    while (!queue.empty()) {
        const auto [current, distance] = queue.front();
        if (current == target) {
            return distance;
        }
        queue.pop();
        visited[current] = true;
        for (int i = 0; i < size; ++i) {
            if (m[current][i] == 1 && !visited[i]) {
                queue.push({i, distance + 1});
            }
        }
    }
    return -1;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Point> towns;
    towns.reserve(n);
    for (int i = 0; i < n; ++i) {
        Point p;
        std::cin >> p.x >> p.y;
        towns.push_back(p);
    }
    int maxLength;
    std::cin >> maxLength;
    int source, target;
    std::cin >> source >> target;
    --source;
    --target;

    Matrix m = createGraph(towns, maxLength);
    std::cout << bfs(m, source, target) << '\n';
}
