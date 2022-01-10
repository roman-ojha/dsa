/*
->                  ________        ________        ________
          top ----> |   |   |-----> |   |   |-----> |   |   |----> NULL
                    ---------       ---------       --------- 
                        |
                       Ptr
        ->  a) top will use for push and pop operations
            b) you can set a custom size for a stack in linked list to make isFull() 
        -> Operation:
            d) isEmpty() -> (top==NULL)
            e) isFull() -> when Heap memory is exhausted(finished) [ptr==NULL]

-> Head or first side will be used fo push and pop operation because we can do the operation in just O(1)
-> Head is now referred as top
-> stack empty condition when(top==NULL)
-> stack full when -> Heap memory is exhausted
-> you can always set a custom size of the stack 
*/