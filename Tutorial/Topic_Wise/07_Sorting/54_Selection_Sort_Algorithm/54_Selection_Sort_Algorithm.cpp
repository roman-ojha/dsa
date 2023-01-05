/*
    # Selection sort:
        8,0,7,1,3

    Selection sort Process:
        array = 8,0,7,1,3
        min =8

    1) 1st Pass (4 Comparision and 1 possible Comparision)
        8,0,7,1,3
        min =0
        0,8,7,1,3 -> swap 8,0

    2) 2nd Pass (3 Comparision and 1 possible Comparision)
        min=1
        0,1,7,8,3 -> swap 8,1
    
    3) 3rd Pass (2 Comparision and 1 possible Comparision)
        min= 3
        0,1,3,8,7 -> swap 7,3

    4) 4th Pass (1 Comparision and 1 possible Comparision)
        min=7
        0,1,3,7,8 -> swap 8,7

    Length of array(n) =5
    No. of Passes=n-1
    Total Comparision:
        (n-1)+...3+2+1 = n(n-1)/2 = O(n^2)
    Max Swaps = n-1

    -> Stable? = This is Not the Stable Algorithm
    -> Adaptive? = This is Not the Adaptive Algorithm
    -> sorting in minimum number of swaps
*/