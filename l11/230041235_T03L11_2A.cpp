#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Vertex {
   public:
    int id;
    int color;  // 0: unvisited, 1: visiting, 2: visited (white, gray, black)
    int dist;
    int parent;

    Vertex(int vertexId) {
        id = vertexId;
        color = 0;
        dist = -1;
        parent = -1;
    }
};

class Graph {
   public:
    int v;
    vector<vector<int>> adjList;
    vector<Vertex> nodes;
    vector<pair<int, int>> edges;

    Graph(int vertices) {
        v = vertices;
        for (int i = 0; i < v; i++) {
            adjList.push_back(vector<int>());
            nodes.push_back(Vertex(i));
        }
        // nodes.resize(v);
    }
    void addEdge(int u, int v) {
        u--;
        v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void printAdjList() {
        for (int i = 0; i < v; i++) {
            cout << i + 1 << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor + 1 << " ";
            }
            cout << endl;
        }
    }

    queue<int> bfs(int s) {
        s--;  // convert to 0-based index
        // initialize all vertices to white/0
        for (int i = 0; i < v; i++) {
            nodes[i] = Vertex(i);
        }

        // make source gray
        nodes[s].color = 1;
        nodes[s].dist = 0;

        queue<int> bfsQueue;
        queue<int> q;

        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            bfsQueue.push(u);

            for (int adj : adjList[u]) {
                if (nodes[adj].color == 0) {
                    nodes[adj].color = 1;
                    nodes[adj].dist = nodes[u].dist + 1;
                    nodes[adj].parent = u;

                    q.push(adj);
                    edges.push_back({u, adj});
                }
            }

            nodes[u].color = 2;
        }
        return bfsQueue;
    }

    void vxDist() {
        cout << "Distances from source:" << endl;
        for (Vertex v : nodes) {
            cout << v.id + 1 << "(" << v.dist << ") ";
        }
        cout << endl;
    }

    void pathFromSource(int s, int d) {
        if (s == d) {
            cout << s + 1;
        } else if (nodes[d].parent == -1) {
            cout << "No path from " << s + 1 << " to " << d + 1 << endl;
        } else {
            pathFromSource(s, nodes[d].parent);
            cout << " -> " << d + 1;
        }
    }
};

int main() {
    int v, e, s;
    cin >> v >> e >> s;
    Graph g(v);

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.printAdjList();
    queue<int> bfsQueue = g.bfs(s);

    cout << "\nBFS Order: ";
    while (!bfsQueue.empty()) {
        cout << bfsQueue.front() + 1 << " ";
        bfsQueue.pop();
    }
    cout << endl << endl;

    g.vxDist();

    cout << endl << endl;

    cout << "Paths from source: " << endl;
    for (int i = 0; i < v; i++) {
        cout << i + 1 << ": ";
        g.pathFromSource(s - 1, i);
        cout << endl;
    }

    cout << endl << endl;

    cout << "Edges in BFS Tree: " << endl;
    for (auto edge : g.edges) {
        cout << edge.first + 1 << " " << edge.second + 1 << endl;
    }
    return 0;
}