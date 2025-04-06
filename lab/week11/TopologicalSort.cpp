#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

struct Graph
{
    int v;
    list<int> *adj;
};

vector<int> indegree(Graph &g)
{
    vector<int> in_degree(g.v, 0);
    for (int i = 0; i < g.v; i++)
    {
        for (int u : g.adj[i])
        {
            in_degree[u]++;
        }
    }
    return in_degree;
}

list<int> topologicalSort(Graph &g)
{
    vector<int> in_degree = indegree(g);
    queue<int> q;
    for (int i = 0; i < g.v; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }
    list<int> order;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        order.push_back(v);
        for (int u : g.adj[v])
        {
            if (--in_degree[u] == 0)
            {
                q.push(u);
            }
        }
    }
    return order;
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
    list<int> result = topologicalSort(g);
    for (int v : result)
    {
        cout << v << " ";
    }
    delete[] g.adj;
    return 0;
}

// Sample Output:
// Enter number of vertices: 6
// Enter number of edges for vertex 0: 2
// Enter the edges: 1 2
// Enter number of edges for vertex 1: 1
// Enter the edges: 3
// Enter number of edges for vertex 2: 1
// Enter the edges: 3
// Enter number of edges for vertex 3: 2
// Enter the edges: 4 5
// Enter number of edges for vertex 4: 0
// Enter number of edges for vertex 5: 0
// 0 1 2 3 4 5
