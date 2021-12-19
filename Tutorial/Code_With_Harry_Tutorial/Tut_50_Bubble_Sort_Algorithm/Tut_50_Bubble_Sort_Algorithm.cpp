/*
    7,11,9,2,17,4
    After Bubble sort
        -> 2,4,7,9,11,17

    Bubble sorting Process:
        7,11,9,2,17,4

    1st Pass:   -> 5 Comparisons, 5 posible swaps, (n-1) Comparison
        7,11,9,2,17,4 -> no need to swap 11,7
        7,9,11,2,17,4 -> swap ll,9
        7,9,2,11,17,4 -> swap 11,2
        7,9,2,11,17,4 -> no need to swap 11,17
        7,9,2,11,4,|17| -> swap 17,4 (here bigest element came to end index)

    2nd Pass:   -> 4 Comparisons, 4 possible swaps, (n-2) Comparison
        7,9,2,11,4,17 
        7,2,9,11,4,17 -> swap 9,2
        7,2,9,11,4,17 -> no need to swap 11,9
        7,2,9,4,|11,17| -> swap 11,4

    3rd Pass:   -> 3 Comparisons, 3 Possible swaps, (n-3) Comparison
        2,7,9,4,11,17 ->swap 7,2
        2,7,9,4,11,17 -> no nedd to swap 9,7
        2,7,4,|9,11,17| -> swap 9,4

    4th Pass:   -> 2 Comparisons, 2 Possible swaps, (n-4) Comparison
        2,7,4,9,11,17   -> no need to swap 2,7
        2,4,|7,9,11,17| -> swap 7,4

    5th Pass:   -> 1 Comparisons, 1 Posible swaps, (n-5) Comparison
        2,|4,7,9,11,17| -> no need to swap 4,2

        |2,4,7,9,11,17| -> sorted array (no need another pass)


    no of Passes = n-1
    Total Number of Comparisons
        1+2+3+4+......+(n-1) = n(n-1)/2 = O(n^2)
    -> It is stable Algorithm
    -> this is not recursive algorithm
    -> by default this is not the Adaptive algorithm (because if the array is already sorted then also we need to perform the same task) but we can make it Adaptive algorithm

    *) Why it is called as Bubble sorting ?
        <----lighter element
        heavier element-----> 
        |2,4,7,9,11,17|
*/