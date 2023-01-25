/*
    # Data Structure(DS):
        -> Data Strcture can be classified into two categories
        1) Linear Data Structure
            a) Static
                I) Array
            b) Dynamic
                I)   Linked List
                II)  Queue
                III) Stack
        2) Non-Linear Data Structure
            a) Tree
            b) Graph

    # Graph
        => A Graph is a non-linear data structure that consists of a finite set of vertices(nodes) and a set of edges connecting them
        *) Applications of Graph
            1) google maps 
            2) Facebook
            3) WWW
            4) Flight network
            5) Product Recommendations
        => Graph Properties
            1) Connected / disconnected Graphs
                => A graph is said to be connected if there exist at least one path between every pair of vertices otherwise its is disconnected.
            2) Directed / Undirected graph
                => In directed graph, each edge has a direction which determines the traversal order
                => In an undirected traph the edges are unidirectional, with no direction associated with them. hence, the graph can be traversed in either direction
            3) Weighted graph
                => A graph where each edges has a numerical weight assigned to it,
            4) Cyclic /Acyclic Graph
                => Cyclic graph - A directed graph containing at least one graph cycle. A cyclic graph possessing exactly one (undirected, simple) Cycle is called a unicyclic graph.
                => Acyclic graph(DAG) - A directed graph that is not cyclic.
            5) Dense / Sparese graph
                => Dense graph is a graph in which the number of edges is close to the maximal number of edges.
                => Spares graph is a graph in which the number of edges is close to the minimal number of edges.
            6) Simple graph
                => Simple graph - A Graph without loops and without multiple edges between two nodes
            7) complete Graph
                => Complete graph - A undirected graph in which every pair of distinct vertices is connected by a unique edge. Every complete graph is also a simple graph.
            8) Strongly connected graph
                => A directed graph is called strongly connected if there is a path in each direction between each pair of vertices of the graph.
        => Graph terminology
            1) Adjacency
                => Adjacent vertices - if there is an edge between the two vertices
                => Adjacent edges - if there is a common vetex between the two edges.
            2) Degree
                => For undirected graph:
                    Degree - Number of vertices adjacent to the vertex V.
                => For directed graph:
                    Indegree - Number of incomming edges into the vertex V.
                    Outdegree - Number of outgoing edges for the vertex V.
                => Sum of indegree and outdgree is even in graph?
                    Its due to a handshaking property which states that:" when you add the indgrees and outdgrees of all the nodes you get the twice the times number edges"
            3) Path
                => A path is a sequence of distinct vertices such that two consecutive vertices are adjacent
            4) Cycle
                => A closed path is called a cycle. i.e a path in which the only repeated vertices are the first and last vertices.
            5) Walk
                => A walk is a sequence of vertices and edges of a graph i.e if we traverse a graph then we get a walk. Vertex and edges can be repeated.
*/