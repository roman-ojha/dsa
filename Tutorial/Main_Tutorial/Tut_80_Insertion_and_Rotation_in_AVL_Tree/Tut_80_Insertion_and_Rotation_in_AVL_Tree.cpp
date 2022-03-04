/*

    # LL Rotation in a AVL tree?
        -> Unbalanced Tree:
                7
            L  /
              5
          L  /
            4

        -> after Rotation: 
                5
               / \
              4   7

    # RR rotation in an AVL Tree?
        -> Unbalanced Tree:
                7
                 \  R
                  9
                   \  R
                    11

        -> after Rotation:
                9
               / \
              7   11
    
    # LR rotation in an AVL Tree?
        -> Unbalanced Tree:
                7
            L  /
              4
               \  R
                5

        -> after Double Rotation:
            -> first anti clockwise rotation:
                    7
                  /
                5
               /
              4 
            -> second clockwise rotation:
                    5
                   / \
                  4   7

    # RL rotation in an AVL Tree?
        -> Unbalanced Tree:
                7
                 \  R
                  11
                 /  L
                10

        -> after Double Rotation:
            -> first  clockwise rotation:
                    7
                     \
                     10
                      \
                      11    
            -> second anti clockwise rotation:
                    10
                   / \
                  7   11

*/