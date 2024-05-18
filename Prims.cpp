#include <limits.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// Number of vertices in the graph
#define V 9

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(vector<int> dist, vector<bool> sptSet)
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function that implements Prim's algorithm for minimum spanning tree problem
void printMST(vector<int> parent, vector<int> graph[V])
{
    cout << "Edge   Weight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "   " << graph[i][parent[i]] << endl;
}

// Function to construct MST using Prim's algorithm
void primMST(vector<int> graph[V])
{
    vector<int> dist(V, INT_MAX); // The output array. dist[i] will hold the shortest
                                  // distance from vertex i to the constructed MST

    vector<bool> sptSet(V, false); // sptSet[i] will be true if vertex i is included in MST

    dist[0] = 0; // First node is always included in MST. Set it to 0.

    vector<int> parent(V, -1); // An array to store constructed MST. parent[i] stores the parent of i in MST

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if it is not in sptSet, there is an edge from u to v,
            // and total weight of path from src to v through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

// Driver code
int main()
{
    /* Let us create the example graph discussed above */
    vector<int> graph[V];

    graph[0].push_back(7);
    graph[0].push_back(8);
    graph[0].push_back(10);

    graph[1].push_back(7);

    graph[2].push_back(8);
    graph[2].push_back(10);

    graph[3].push_back(1);
    graph[3].push_back(2);
    graph[3].push_back(6);

    graph[4].push_back(2);
    graph[4].push_back(6);

    graph[5].push_back(6);
    graph[5].push_back(11);

    graph[6].push_back(11);

    graph[7].push_back(3);
    graph[7].push_back(5);

    graph[8].push_back(5);

    // Print the solution
    primMST(graph);

    return 0;
}