/*
    Queue:  (FIFO)
        -> Insertation from Rare
        -> Deletion from front
    DEQueue: 
        -> Insertation from Rare or front
        -> Deletion from front or rare
            -> Two types of DEQueue:
                1) Restricted Input Dequeue
                    -> Insertion from front Not allowed
                2) Restricted Output Dequeue
                    -> Deletion from rear is not allowed
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