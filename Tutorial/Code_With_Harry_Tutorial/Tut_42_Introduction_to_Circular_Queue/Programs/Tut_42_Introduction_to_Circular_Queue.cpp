/*
Drabacks of Queue using Array:
-> Space is not used efficiently
-> after increnment of front end we can use previous block of memory in linear Queue

so, to solve the problem 
    -> when (front==rear)
        then , front = -1 // starting fornt end again from the starting position
        This is one solution
        but there is also drawback in this one

so, Circular Queue will help us to do that
Circular Increnment:
    i=i+1 -> Lienar increnment
    i=(i+1)%size; ->circular increnment
    Explation:
        when i=0;
            i=(0+1)%6=1;
        when i=1;
            i=(1+1)%6=2;
        when i=2;
            i=(2+1)%6=3;
        when i=3;
            i=(3+1)%6=4;
        when i=4;
            i=(4+1)%6=5;
        when i=5;
            i=(5+1)%6=0;                      
*/