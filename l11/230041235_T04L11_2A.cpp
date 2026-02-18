#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Edge {
   public:
    int u;
    int v;
    int type;  // 0: tree, 1: back, 2: forward, 3: cross
    Edge(int u, int v, int type) {
        this->u = u;
        this->v = v;
        this->type = type;
    }
};

class Vertex {
   public:
    int id;
    int color;  // 0: unvisited, 1: visiting, 2: visited (white, gray, black)
    int pred;
    int discT;
    int finT;

    Vertex(int vertexId) {
        id = vertexId;
        color = 0;
        pred = -1;
        discT = -1;
        finT = -1;
    }
};

class Graph {
   public:
    int v;
    int time = 0;
    vector<Vertex> nodes;
    vector<vector<int>> adjList;
    vector<Edge> edges;

    Graph(int vertices) {
        v = vertices;
        for (int i = 0; i < v; i++) {
            adjList.push_back(vector<int>());
        }

        for (int i = 0; i < v; i++) {
            nodes.push_back(Vertex(i));
        }
    }

    void addEdge(int u, int v) {
        u--;
        v--;
        adjList[u].push_back(v);
        // adjList[v].push_back(u);
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

    void DFS() {
        for (int i = 0; i < v; i++) {
            if (nodes[i].color == 0) {
                dfs(i);
            }
        }
    }

    void dfs(int s) {
        nodes[s].color = 1;  // gray
        time += 1;
        nodes[s].discT = time;

        cout << s + 1 << " ";  // print vertex as it's visited
        // visit each child

        for (int neighbor : adjList[s]) {
            Edge edge(s, neighbor, 0);  // tree edge by default
            Vertex u = nodes[s];
            Vertex v = nodes[neighbor];
            if (v.color == 0) {
                edge.type = 0;  // tree edge
            } else if (v.color == 1) {
                edge.type = 1;  // back edge
            } else if (v.color == 2 && u.discT < v.discT) {
                edge.type = 2;  // forward edge
            } else if (v.color == 2 && u.discT > v.discT) {
                edge.type = 3;  // cross edge
            }

            edges.push_back(edge);

            if (nodes[neighbor].color == 0) {
                nodes[neighbor].pred = s;
                dfs(neighbor);
            }
        }

        nodes[s].color = 2;  // black
        time += 1;
        nodes[s].finT = time;
    }
};

int main() {
    int v, e, s;
    cin >> v >> e;
    s = 1;
    s--;  // convert to 0-based index
    Graph g(v);
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.printAdjList();

    cout << "\nDFS Order: ";
    g.DFS();

    cout << endl
         << endl;

    cout << "Timestamp of Vertex (Discovery/Finishing)" << endl;
    for (Vertex vertex : g.nodes) {
        cout << vertex.id + 1 << "(" << vertex.discT << "/" << vertex.finT << ") ";
    }

    cout << endl
         << endl;
    
    cout << "Edge Classifications" << endl;
    for (Edge edge : g.edges) {
        string type;
        switch (edge.type) {
            case 0:
                type = "Tree Edge";
                break;
            case 1:
                type = "Back Edge";
                break;
            case 2:
                type = "Forward Edge";
                break;
            case 3:
                type = "Cross Edge";
                break;
        }
        cout << edge.u + 1 << " -> " << edge.v + 1 << ": " << type << endl;
    }
    return 0;
}