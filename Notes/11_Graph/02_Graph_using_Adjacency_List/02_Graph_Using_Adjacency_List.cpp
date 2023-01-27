/*
    => We can represent Adjacency list in the form of:
        1. Array of Array list
            -> V : total vertex
            -> int Array[]
            -> ArrayList<Edge> Graph[V]
        2. Hashmap

    => Edge:
        -> class Edge{
            int src;
            int dest;
        }
    => Or for edge we can use C++ STL std::pair
*/
// #include <iostream>
// #include <vector>
// using namespace std;

// class Edge
// {
//     int src;
//     int dest;

// public:
//     Edge(int s, int d) : src(s), dest(d) {}
// };

// void createGraph(vector<Edge> *graph)
// {
// }

// int main()
// {
//     // Number of vertex
//     int V = 4;

//     vector<Edge> *graph = new vector<Edge>[V];

//     return 0;
// }