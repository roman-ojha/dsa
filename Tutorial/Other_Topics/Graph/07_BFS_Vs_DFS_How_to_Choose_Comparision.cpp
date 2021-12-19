/*
    => BFS vs DFS 
        => BFS:
            -> Start traversal from the root node and visit nodes is a level by level manner(i.e., visiting the ones closest to the root first)
            -> User FIFO data structure e.g Queue
            -> Time complexity: O(V+E)
            -> Space Complexity: O(V), O(b^d)
                b= branching factor, avg.outdegree
                d= distance from start node
            -> Optimal
                -> A search algorithm is optimal if when it finds a solution, it is the best one(e.g the shortest)
        => DFS:
            -> Start the traversal from the root node and visit nodes as far as possible from the root node (i.e, depth wise)
            -> Uses LIFO data structure e.g Stack
            -> Time complexity: O(V+E)
            -> Space Complexity: O(V), O(bd)
            -> Not Optimal

        => Which one to choose?
            -> Depends on the structure of the graph and the number and location of searched-for items
                *) If you know a solution is not far from the root of the tree -> BFS
                *) If solutions are frequent but located deep on the tree -> DFS
                *) if the tree is very deep and solution are rare, DFS would e too slow
                *) if the tree is very wide, and BFS might need to much memory, so it might be completely impractical
            -> FaceBook/Linkedin friend suggetions?
                -> BFS traversal
            -> Shortest path between two nodes in a graph?
                -> BFS traversal
            -> Longest path between two nodes in a graph?
                -> DFS traversal
            -> Solve maze of sudoku having only one solution?
                -> DFS traversal
            -> Check if you could reach a node from another on a given graph
                -> BFS/DFS traversal
            -> Detect cycle in a graph
*/