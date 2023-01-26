/*
    # Deletion in max heap
        -> we can't delete any value from the tree
        -> we can only delete the root node
        -> Now the last index value will come to root node
        -> Now, again try to make it max heap tree
        -> To make the max heap tree:
            -> if parent node is less then the child node in that case we have to make it a max heap
            -> first compare two child node
            -> if a & b are child node
            -> and a > b then
            -> compare 'a' with parent node
            -> if a > parent in that case swap(a,parent)
            -> repeat this until it will place there where it belong to satisfy the max heap property
        -> In insertion we go from bottom to top & in Deletion we go from top to bottom
        ->
            left child = 2 * i
            right child = (2 * i) + 1
            greater child = left child > right child ? 2 * i : (2 * i ) + 1
            if(greater child > parent){
                swap(greater child, parent);
            }

        -> Sorting concept:
            -> n = 11
            -> {70, 60, 40, 45, 50, 39, 16, 10, 9, 35, 5}
            -> if we will put the root node that we just delete from the max heap into last index which will not consider as max heap tree node
                -> {5, 60, 40, 45, 50, 39, 16, 10, 9, 35, 70}
                -> n = 10
            -> make it max heap
                -> {60, 5, 40, 45, 50, 39, 16, 10, 9, 35, 70}
                -> {60, 50, 40, 45, 5, 39, 16, 10, 9, 35, 70}
                -> {60, 50, 40, 45, 35, 39, 16, 10, 9, 5, 70}
            -> Again delete root node
                -> {5, 50, 40, 45, 35, 39, 16, 10, 9, 60, 70}
            -> Make it max heap again:
            -> after doing deleting all the node from max heap what we can see is the array will be in sorted order
            -> and it would be in ascending order
            -> if we will use min heap in that case it will be in descending order

        -> Illustration:
            Suppose the Heap is a Max-Heap as:
                    10
                  /    \
                 5      3
                / \
               2   4

                The element to be deleted is root, i.e. 10.

                Process:
                The last element is 4.

                Step 1: Replace the last element with root, and delete it.
                    4
                  /    \
                 5      3
                /
               2

                Step 2: Heapify root.
                Final Heap:
                    5
                  /    \
                 4      3
                /
               2
*/