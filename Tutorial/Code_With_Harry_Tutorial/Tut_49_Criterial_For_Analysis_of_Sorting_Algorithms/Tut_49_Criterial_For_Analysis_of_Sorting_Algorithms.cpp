/*
    # Analysis Criterial For Sorting Algorithm
        1) Time Complexity
        2) Space Complexity
            -> Inplace sorting algorighm
                -> An in-place algorithm is an algorithm that does not need an extra space and produces an output in the same memory that contains the data by transforming the input ‘in-place’. However, a small constant extra space used for variables is allowed.
        3) Stability
            -> https://www.geeksforgeeks.org/stability-in-sorting-algorithms/

            ->Befor sorting
                1   3   8   7   1   2
                A   B   C   D   E   F

            ->After sorting
                1   1   2   3   7   8       -> This is the Stable sorting Algorighm
                A   E   F   B   D   C

        4) Internal/External Sorting Algorithm:
            -> Internal SA:
                -> All the data is loaded into the memory
            -> External SA:
                -> All the data is not loaded into the memory
        5) Adaptive:
            -> Already sorted data takes less time
        6) Recursive/Non-Recursive SA:
            -> Recursive if it use recursion
*/