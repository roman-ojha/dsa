/*
    # Trees:
        -> n nodes => n-1 edges
        -> Terminology:
            1) Root:
                -> Topmost Node
            2) Parent:
                -> NOde which connects to the child
            3) Child:
                -> Node which is connected by another node 
            4) leaf/External node:
                -> Node which doesn't have child
            5) Internal node:
                -> Node with atleast one children
            6) Depth:
                -> Number of edges from root to the node
            7) Height: 
                -> No of edges from node to the depest leaf
            8) Sibling:
                -> Nodes belonging to the same parent
            9) Ancentors:
                -> all parents upto root from the Node 
            10) Descendents:
                -> all child from the Node

*/

/*

                             __________
                            |____7____|  ----> root,parent,Internal [height =3]
                               /|\
                             /  | \
                           /    |  \
                         /      |   \   -> depth = 1
                       /        |    \
                     /          |     \
                 _______    ________ _________
                |___8__|   |___2___||___11___| ----> parent,child,Internal [depth = 1]
                   / \         /        \
                 /    \       /          \  -> depth = 2
             ______  ______  ______    ______
            |__1__| |__0__| |__2__|   |__3__|  ---->parent,child,Internal [depth = 2]
               |                        /
         leaf,child                    /    
                                   ______
                                  |__4__| ----->leaf,child
*/