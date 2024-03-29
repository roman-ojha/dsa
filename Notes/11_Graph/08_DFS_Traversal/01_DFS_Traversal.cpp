/*
    # Depth first Search - DFS
    => Like a single search proging unknown area as deeply as possible, retreating only when meeting dead ends.
    => Start traversal from a node and goes as far as it can a given path, then backtracks until it finds an unexplored path, and then explores it.
    => Which data structure to use?
        *) LIFO data structure (Stack)
    => How to avoid cycles?
        *) Keep track of visited nodes
    => Algorithm
        st = stack
        visited = array
        step 01: add start vertex to stack st
                mark start as visited
        step 02: while st != empty:
                    v = top of stack, pop stack
                    output
                    for each adjacent vertex av of v:
                        if av is not visited:
                            add av to stack st
                            mark av as visited
    => Algorithm (Recursive):
        -> as we know that the recursion use the implicit Stack so instead of using an external stack we will use the implicit stack that is use in recursion
        => dfs(v):
            mark v as visited
            for each adjacent vertex av of v:
                if av is not visited:
                    dfs(av)
    => Applications:
        *) topological sorting
        *) Scheduling problems
        *) Cycle detection in graph
        *) Solving puzzles with only one solution e.g maze
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
}

void dfs_iterative(vector<int> graph[], int start)
{
    vector<bool> visited(graph->size(), false);
    stack<int> st;
    st.push(start);
    visited[start] = true;
    while (!st.empty())
    {
        int v = st.top();
        cout << v << "  ";
        st.pop();
        // Enqueue all adjacent nodes of v and mark them visited
        for (auto i = graph[v].begin(); i != graph[v].end(); i++)
        {
            if (!visited[*i])
            {
                st.push(*i);
                visited[*i] = true;
            }
        }
    }
}

void dfs_recursive(vector<int> graph[], vector<bool> &visited, int node)
{
    visited[node] = true;
    cout << node << "  ";
    for (auto i = graph[node].begin(); i != graph[node].end(); i++)
    {
        if (!visited[*i])
            dfs_recursive(graph, visited, *i);
    }
}

int main()
{
    int V = 7; // vertices
    vector<int> graph[V];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);

    cout << "DFS traversal iterative starting from node 0:"
         << "  ";
    dfs_iterative(graph, 0);
    // Starting the traversal form node 0
    cout << endl;

    cout << "DFS traversal recursive starting from node 0:"
         << "  ";
    vector<bool> visited(graph->size(), false);
    dfs_recursive(graph, visited, 0);

    return 0;
}