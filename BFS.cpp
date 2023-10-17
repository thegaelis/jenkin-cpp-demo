#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

const int V = 6;
vector<int> graph[V];

void addEdge(int v, int w) {
    graph[v].push_back(w);
}

void BFS(int start, ofstream& output) {
    bool visited[V] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        output << current << " ";
        q.pop();

        for (size_t i = 0; i < graph[current].size(); ++i) {
        int neighbor = graph[current][i];
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            q.push(neighbor);
        }
}
    }
}

int main() {
    ifstream input("input.txt");
    if (!input) {
        cerr << "Loi mo file input" << endl;
        return 1;
    }

    ofstream output("output.txt");
    if (!output) {
        cerr << "Loi file output" << endl;
        input.close();
        return 1;
    }

    int edges;
    input >> edges;

    for (int i = 0; i < edges; ++i) {
        int v, w;
        input >> v >> w;
        addEdge(v, w);
    }

    int start;
    input >> start;
    input.close();

    output << "Duyet theo chieu rong\nCanh bat dau " << start << ": ";
    BFS(start, output);
    output << endl;
    output.close();

    cout << "Da xuat ra file output" << endl;

    return 0;
}