#include <iostream>
#include <queue>
#include <list>
using namespace std;

struct Graph
{
    int v;
    list<int> *adj;
};

void BFS(Graph &g)
{
    bool visited[g.v] = {false};
    queue<int> q;
    int start;
    cout << "Enter starting vertex: ";
    cin >> start;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int u : g.adj[v])
        {
            if (!visited[u])
            {
                q.push(u);
                visited[u] = true;
            }
        }
    }
}

int main()
{
    Graph g;
    cout << "Enter number of vertices: ";
    cin >> g.v;
    g.adj = new list<int>[g.v];
    for (int i = 0; i < g.v; i++)
    {
        cout << "Enter number of edges for vertex " << i << ": ";
        int edges;
        cin >> edges;
        cout << "Enter the edges: ";
        for (int j = 0; j < edges; j++)
        {
            int edge;
            cin >> edge;
            g.adj[i].push_back(edge);
        }
    }
    cout << "BFS Traversal: ";
    BFS(g);
    delete[] g.adj;
    return 0;
}

// Sample Output:
// Enter number of vertices: 4
// Enter number of edges for vertex 0: 2
// Enter the edges: 1 2
// Enter number of edges for vertex 1: 1
// Enter the edges: 3
// Enter number of edges for vertex 2: 1
// Enter the edges: 3
// Enter number of edges for vertex 3: 0
// BFS Traversal: Enter starting vertex: 0
// 0 1 2 3
