/*
if the element in queue is empty then the back pointer of the back index will be -1
if the element in queue is fill with one element then the value of back will be 0

and while increasing the element in the queue the back value will all increased 

In a queue total size of the queue is denoted by "size"

Queue:
      -1   0   1   2   3   4   5
       |   |   |   |   |   |   |
         ________________________
        |_8_|___|___|___|___|___|
          |
        back
      -1   0   1   2   3   4   5
       |   |   |   |   |   |   |
         ________________________
        |_8_|_5_|___|___|___|___|
             |
           back


Properties: Front => To track front end
            rear => To track back end

Method: enqueue() => inserting element at the back end
            Time complexity of the enqueue will be O(1) 
                Increnment "backend" and insert at "backend"
        dequeue() => removing element form the front end
            NOTE:: after calling dequeue function we have to shift all the element from the next index to the front end so,
            Time complexity of the dequeue will be O(n) so,
                increnment "frontend" and remove 
        queueEmpty() => if(frontend==backend)
        queueFull() => if(backend==size-1)
*/