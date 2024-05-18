#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
    int V;
    vector<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::DFS(int v)
{
    vector<bool> visited(V, false);
    stack<int> stack;

    stack.push(v);
    visited[v] = true;

    while (!stack.empty())
    {
        int currentVertex = stack.top();
        stack.pop();

        cout << currentVertex << " ";

        for (int i = 0; i < adj[currentVertex].size(); i++)
        {
            int adjVertex = adj[currentVertex][i];
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                stack.push(adjVertex);
            }
        }
    }
}
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "DFS traversal of the graph: ";
    g.DFS(2);

    return 0;
}