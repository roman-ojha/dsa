/*
    Queue:  (FIFO)
        -> Insertion from Rare
        -> Deletion from front
    DEQueue:
        -> Insertion from Rare or front
        -> Deletion from front or rare
            -> Two types of DEQueue:
                1) Restricted Input Dequeue
                    -> Insertion from front Not allowed
                    -> In this deque, input is restricted at a single end but allows deletion at both the ends.
                2) Restricted Output Dequeue
                    -> Deletion from rear is not allowed
                    -> In this deque, output is restricted at a single end but allows insertion at both the ends.
        DEQueue - ADT
            1) data -> Same as Queue
            2) operations :
                a) isEmpty()
                b) isFull()
                c) enqueueF() -> front
                d) enqueueR() -> rare
                e) dequeueF() -> front
                f) dequeueR() -> rare
                g) traversal()
                h) initialize()
*/