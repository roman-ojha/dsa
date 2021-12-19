/*
    # why do we need an AVL Tree?
        -> Almost all the operations in a binary search tree are of order O(h) where h is the height of the tree.
        -> if we don't plan our tree properly, this height can get as high as n where n is the number of nodes in a BST(skewed tree)
        -> To guarantee an upper bound of o(log n) for all these operations , we use balanced trees

    #What is an AVL Tree?
        *) Height balanced binary search trees
        *) Height difference between heights of left and right subtrees for every nodes is less than or equal to 1.
        *) Balanced factor = Height of right subtree- Height of left subtree
            -> |Hl - Hr| >= 1
        *) Can be -1, 0 or 1 for a node to ba balanced in a Binary search tree
        *) Can be -1, 0 or 1 for all nodes of an AVL tree
        *) for a tree to be balanced 
            -> |BF| <=1 : BF = Balanced factor
*/