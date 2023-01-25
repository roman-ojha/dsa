/*
 # from geeksfrogeeks

We have discussed BST search and insert operations. In this post, the delete operation is discussed. When we delete a node, three possibilities arise.
1) Node to be deleted is the leaf: Simply remove from the tree.

              50                            50
           /     \         delete(20)      /   \
          30      70       --------->    30     70
         /  \    /  \                     \    /  \
       20   40  60   80                   40  60   80
2) Node to be deleted has only one child: Copy the child to the node and delete the child

              50                            50
           /     \         delete(30)      /   \
          30      70       --------->    40     70
            \    /  \                          /  \
            40  60   80                       60   80
3) Node to be deleted has two children: Find inorder successor of the node. Copy contents of the inorder successor to the node and delete the inorder successor. Note that inorder predecessor can also be used.

              50                            60
           /     \         delete(50)      /   \
          40      70       --------->    40    70
                 /  \                            \
                60   80                           80

*/

/*
    #Deleting a node in a BST case:
        Case 1: The node is a leaf node
        Case 2: The node is a non leaf node
        Case 3: The node is the root node / node between BST

    Case 1)
        step 1 -> search the node
        step 2 -> Delete the node
        step 3 -> make parent->child node NULL

    Case 2)
        after deleting the the node which is non leaf node
        in that case the place of deleted node will taken by:
            a) Inorder pre(predecessor) OR b) Inorder post(successor)
            Ex: Inorder: 1,2,3,4,5,6
                -> if we want to delete '4' then it has to replace by either 3 or 5
    Case 3)
        Ex:Inorder: 1,3,4,6,7,8,10,13,14

        if we want to delete 8 then first we have to delete and replace by either 7 or 10
        after that if we will chose 10 then we again have to replace 10 by either 8 or 13
        step 3: we had already came from 8 so we will going to chose 13 and in this case 13 is the leaf node so replacing process will finished

        step 1 -> Search for the node
        step 2 -> Search for Ipre(inorder pre) and Ipost(inorder post)
        step 3 -> Keep doing this until the tree has no empty nodes

*/
