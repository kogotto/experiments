#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

using Graph = vector<vector<int>>;

Graph readGraph(int n) {
    Graph result;
    result.reserve(n);
    for (int i = 0; i < n; ++i) {
        result.push_back(vector<int>());
        result.back().reserve(n);
        for (int j = 0; j < n; ++j) {
            int a;
            cin >> a;
            result.back().push_back(a);
        }
    }
    return result;
}

void writeGraph(const Graph& graph) {
    for (const auto& row : graph) {
        for (const auto& elem : row) {
            cout << setw(3) << elem;
        }
        cout << endl;
    }
}

struct DNodeResult {
    /* DNodeResult */
    int minLength = numeric_limits<int>::max();
    int prevNode;
};
using DResult = vector<DNodeResult>;

void writeResult(const DResult& result) {
    for (const auto& l : result) {
        /* cout << setw(3) << l.minLength << " "; */
        cout << setw(3) << l.prevNode << " ";
    }
    cout << endl;
}

DResult dijkstra(const Graph& graph, int startNode) {
    const int size = graph.size();
    vector<bool> used(size, false);
    DResult result(size);
    result[startNode].minLength = 0;

    auto nextNode = [&] {
        int min = size;
        for (int i = 0; i < size; ++i) {
            if (used[i]) continue;
            if (min >= size) {
                min = i;
                continue;
            }
            if (result[i].minLength < result[min].minLength) {
                min = i;
            }
        }
        return min;
    };

    for (int i = 1; i < size; ++i) {
        const int currentNode = nextNode();
        auto lengthToNeighbour = [&] (int neighbour) {
            return graph[currentNode][neighbour];
        };
        for (int j = 0; j < size; ++j) {
            if (used[j]) continue;
            const int l = lengthToNeighbour(j);
            if (l == 0) continue;
            const int path = result[currentNode].minLength + l;
            if (path < result[j].minLength) {
                result[j].minLength = path;
                result[j].prevNode = currentNode;
            }
        }
        used[currentNode] = true;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    const Graph graph = readGraph(n);

    const auto result = dijkstra(graph, 0);

    writeGraph(graph);
    writeResult(result);
}
