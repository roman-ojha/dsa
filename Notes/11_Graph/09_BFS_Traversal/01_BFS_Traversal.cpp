/*
    # Graph Traversal(Search)
        => Technique used for visiting each vertex or node of the graph.
        => application:
            *) Finding all reachable nodes (for garbage collection)
            *) Finding the best reachable node (single-player game search) or the minmax best reachable node (two-player game search)
            *) Finding the best path through a graph(for routing and map directions)
        => How are they classified ?
            -> Depending on the order in which vertices are visited.
                *) BFS - Breadth first Search
                *) DFS - Depth first Search

    # Breadth first search - BFS
        => It is same like a Level order traversal in Binary Tree
        => Like an army of soldiers spreading out to cover the area.
        -> Start traversal from a node and explore graph layer wise.
        => Which data structure to use ?
            *) FIFO Data structure (Queue)
                => breadth related to width so, we will use queue
                => but DFS , depth related to height so, we will use Stack in DFS
        => when we are doing graph Traversal we have to avoid cycle
        => How to avoid cycles ?
            *) Keep track of visited nodes
                -> we can keep an array or hash map
        => Algorithm:
            q = queue
            visited = array
            step 01 : add start vertex to queue(q) and mark start as visited
            step 02 : while q!=empty
                        v= front of queue
                        output: v
                        dequeue the q
                        for each adjacent vertex av of v:
                            if av is not visited:
                                add av to queue q
                                mark av as visited
        => Time complexity : O(V + E)
            -> V: number of vertex
            -> E: number of edges
        => Applications:
            *) Peer to peer Network (UTorrent, bittorrent)
            *) Social Networking Websites
            *) GPS Navigation systems
            *) Path finding
            *) Broadcasting in Network
            *) Garbage Collection
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int V = 7; // vertices
void displayGraph(vector<int> graph[])
{
    for (int i = 0; i < V; i++)
    {
        cout << i;
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << " -> " << graph[i][j];
        }
        cout << endl;
    }
}

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].emplace_back(v);
}

void bfs(vector<int> graph[], int start)
{
    vector<bool> visited(graph->size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int v = q.front();
        cout << v << " ";
        q.pop();
        // Enqueue all adjacent nodes of v and mark them visited
        for (auto i = graph[v].begin(); i != graph[v].end(); i++)
        {
            if (!visited[*i])
            {
                q.push(*i);
                visited[*i] = true;
            }
        }
    }
}

int main()
{
    // int V = 7; // vertices
    vector<int> graph[7];
    addEdge(graph, 0, 1);
    // addEdge(<array>,<vertex>,<adjacent>)
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);
    displayGraph(graph);

    // BFS traversal starting from node 0
    cout << "\nBFS: ";
    bfs(graph, 0);
    return 0;
}