/*
struct Node
{
    int data;
    struct Node *next;
};

Deletion can be done for the following cases:

Case1: Deleting the first node
        Process:
            Struct Node *ptr=head;// in this case ptr is also pointing to the same address
            head=head->next; // and in here we are pointing head to the next index
            free(ptr); // becaseu ptr is also pointing to the same address now we can free(delete)
            // Time complexity for this case is O(1)
Case2: Deleting the node at the index
        // Time xomplexity for case will be O(n)
Case3: Deleting the last node
Case4: Deleting the first node with a given value

*/