#include <iostream>
#include <vector>
#include <list>

using namespace std;

void DFS(int v, vector<list<int>> &adj, vector<int> &flag)
{
    flag[v] = 1;
    for (int u : adj[v])
    {
        if (flag[u] == -1)
        {
            DFS(u, adj, flag);
        }
    }
}

int connectedComponents(int N, vector<vector<int>> &edges)
{
    vector<list<int>> adj(N);
    vector<int> flag(N, -1);

    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int count = 0;
    for (int v = 0; v < N; v++)
    {
        if (flag[v] == -1)
        {
            DFS(v, adj, flag);
            count++;
        }
    }
    return count;
}

int main()
{
    int N, E;
    cout << "Enter number of vertices and edges: ";
    cin >> N >> E;

    vector<vector<int>> edges(E, vector<int>(2));
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    int result = connectedComponents(N, edges);
    cout << "Number of connected components: " << result << endl;

    return 0;
}

// Sample Output:
// Enter number of vertices and edges: 6 5
// Enter the edges (u v):
// 0 1
// 0 2
// 3 4
// 4 5
// 2 3
// Number of connected components: 1
