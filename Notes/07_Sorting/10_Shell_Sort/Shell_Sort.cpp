/*
    *) Shell sort
        => For insertion Sort:
            -> EX:
                -> Arr: 23, 29, 15, 29, 31, 7, 9, 5, 2
                -> After some point of time we will get
                -> Arr: 15, 19, 23, 29, 31, | 7, 9, 5, 2
                -> if we have to insert '7' into sorted array then
                    -> number of comparision: 5
                    -> number of swap operation: 5
                -> Arr: 7, 15, 19, 23, 29, 31, | 9, 5, 2
                -> if we have to insert '9' into sorted array then
                    -> number of comparision: 5
                    -> number of swap operation: 5
                -> Arr: 7, 9, 15, 19, 23, 29, 31, | 5, 2

                => So here we ca see that if lest element in array exist on last position of the array
                => and we want to sort it in ascending order in that case we have to do many comparision operation.
                => Here so we are comparing distant element and not near element.
                => Because of that the element that we want to insert could take large amount of comparision & swap operation.
                => That the reason we use shell sort.
        => In shell sorting we compare element that are distance apart rather than adjacent.
            -> Arr: 23, 29, 15, 29, 31, 7, 9, 5, 2
            -> 23 & 7 element are distance apart so we can compare these two element
        => So in shell sort we will calculate the distance/gap between two element.
        => gap is the number of element that exist between these 2 element that we are comparing.
        => EX:
            -> Arr: 23, 29, 15, 29, 31, 7, 9, 5, 2
            -> for 23 & 7 element
            -> gap: 5, swap 23 & 7
            -> for 29 & 9 element
            -> gap: 5, swap 29 & 9
            -> for 15 & 5 element
            -> gap: 5, swap 15 & 5
            -> for 29 & 2 element
            -> gap: 5, swap 29 & 2
            -> so if we will use shell sort, if smaller elements exist in the last position of arr in that case less number of swap & less number of comparision operation is required.
        => So we have to chose the 'gap' sequence, and the efficiency of the sort would depend of the 'gap' sequence.
        => and the gap value will get reduced in every passes
        => so, we calculate the 'gap' for each pass, and then select the element towards the right of gap.
        => In this case we reduce the gap by dividing it by 2.
        => When gap = 1 the shell sort will work same as Insertion sort.
            => EX:
                -> in this case we will take gap = floor(N/2).
                -> First pass, gap1: N/2
                -> second pass, gap2: gap1/2 == N/4
                -> third pass , gap3: gap2/2 == N/8
                -> we will do this until gap == 1
                -> then now the sorting algorithm will work as insertion sort.
        => Shell sort EX:
*/