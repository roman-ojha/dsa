/*
    *) Shell sort
        -> https://youtu.be/SHcPqUe2GZM
        => For insertion Sort:
            -> EX:
                -> Arr: 23, 29, 15, 19, 31, 7, 9, 5, 2
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
            -> Arr: 23, 29, 15, 19, 31, 7, 9, 5, 2
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
            -> NOTE: if swap will be done check for the next and previous element according to the gap value iteratively util we don't have to swap the element
            -> Arr: 23, 29, 15, 19, 31, 7, 9, 5, 2
            -> N = 9
            -> gap = N/2 = 9/2 = 4
            -> 1st pass:
                -> i = 0; j = 4;
                -> if(arr[i] > arr[j]) swap
                -> else no swap
                    -> for 0th element arr[i] = 23:
                    -> element on gap 4 is arr[j] = 31
                    -> here(arr[i] < arr[j]) no swap
                    -> for 31 element on gap 4 is 2
                    -> 23, ___4___, 31, ___4___, 2
                    -> Arr: 23, 29, 15, 19, 31, 7, 9, 5, 2
                -> i++; j++; , i = 1, j = 5
                    -> for 1th element arr[i] = 29:
                    -> element on gap 4 is arr[j] 7
                    -> here(arr[i] > arr[j]) swap
                    // -> 29, ___4___, 7, ___4___
                    -> Arr: 23, 7, 15, 19, 31, 29, 9, 5, 2
                -> i++; j++;
                -> i = 2, j = 6;
                    -> for 2th element arr[i] = 15:
                    -> element on gap 4 is arr[j] = 9
                    -> here(arr[i] > arr[j]) swap
                    -> 15, ___4___, 9
                    -> Arr: 23, 7, 9, 19, 31, 29, 15, 5, 2
                -> i++; j++;
                -> i = 3, j = 7;
                    -> for 3rd element arr[i] = 19:
                    -> element on gap 4 is arr[j] = 5
                    -> here(arr[i] > arr[j]) swap
                    -> 19, ___4___, 5
                    -> Arr: 23, 7, 9, 5, 31, 29, 15, 19, 2
                -> i++; j++;
                -> i = 4, j = 8;
                    -> arr[i] = 31:
                    -> element on gap 4 is arr[j] = 2
                    -> here(arr[i] > arr[j]) swap
                    -> 31, ___4___, 2
                    -> Arr: 23, 7, 9, 5, 2, 29, 15, 19, 31

                    -> here we again compare elm 23 with gap of 4 elm 2
                    -> arr[i] = 2
                    -> arr[i - 4(gap)] = 23
                    -> 23 > 2 : swap
                    -> Arr: 2, 7, 9, 5, 23, 29, 15, 19, 31
                    -> NOTE: on the previous iteration we have not done the comparision because there did not exist any element, or goes beyond 0th index
                -> i++; j++;
                -> j > size of array so stop
            -> gap = N/4 = 2
            -> i = 0; j = gap == 2;
            -> 2nd pass:
                -> Arr: 2, 7, 9, 5, 23, 29, 15, 19, 31
                -> i = 0; j = 2;
                    -> for 0th element arr[i] = 2:
                    -> element on gap 4 is arr[j] = 9
                    -> here(arr[i] < arr[j]) no swap
                    -> Arr: 2, 7, 9, 5, 23, 29, 15, 19, 31
                -> i++; j++;
                -> i = 1, j = 3
                    -> for 1th element arr[i] = 29:
                    -> element on gap 4 is arr[j] 7
                    -> here(arr[i] > arr[j]) swap
                    -> Arr: 2, 5, 9, 7, 23, 29, 15, 19, 31
                    -> compare with previous element if exist
                    -> arr[i - gap(2)] = -1, no element
                -> i++; j++;
                -> i = 2, j = 4;
                    -> for 2th element arr[i] = 9
                    -> element on gap 4 is arr[j] = 23
                    -> here(arr[i] < arr[j]) no swap & no compare with previous element arr[i - gap(2)]
                    -> Arr: 2, 5, 9, 7, 23, 29, 15, 19, 31
                -> i++; j++;
                -> i = 3, j = 5;
                    -> for 3rd element arr[i] = 7
                    -> element on gap 4 is arr[j] = 29
                    -> here(arr[i] < arr[j]) no swap & no compare with previous element arr[i - gap(2)]
                    -> Arr: 2, 5, 9, 7, 23, 29, 15, 19, 31

                -> i++; j++;
                -> i = 4, j = 6;
                    -> arr[i] = 23:
                    -> element on gap 4 is arr[j] = 15
                    -> here(arr[i] > arr[j]) swap
                    -> Arr: 2, 5, 9, 7, 15, 29, 23, 19, 31

                    -> because swapping had been done we will going to check with the previous element of i - gap(2)
                    -> here(arr[i] < arr[i - gap(2)]) no swap
                    -> if no swap then no need to compare with the previous element arr[i - (gap(2) * 2)]
                    -> Arr: 2, 5, 9, 7, 15, 29, 23, 19, 31

                -> i++; j++;
                -> i = 5, j = 7;
                    -> arr[i] = 29:
                    -> element on gap 4 is arr[j] = 19
                    -> here(arr[i] > arr[j]) swap
                    -> Arr: 2, 5, 9, 7, 15, 19, 23, 29, 31

                    -> because swapping had been done we will going to check with the previous element of i - gap(2)
                    -> here(arr[i] < arr[i - gap(2)]) no swap
                    -> if no swap then no need to compare with the previous element arr[i - (gap(2) * 2)]
                    -> Arr: 2, 5, 9, 7, 15, 19, 23, 29, 31


                -> i++; j++;
                -> i = 6, j = 8;
                    -> arr[i] = 23:
                    -> element on gap 4 is arr[j] = 31
                    -> here(arr[i] < arr[j]) no swap & no ned to check for the previous element with the gap or gap(2), arr[i - gap(2)]
                    -> Arr: 2, 5, 9, 7, 15, 19, 23, 29, 31

                -> i++; j++;
                -> j > size of array so stop
            -> gap = N/8 = 1
            // here gap is 1 it will work as insertion sort
            -> i = 0; j = gap == 1;
            -> 3rd pass:
                -> Arr: 2, 5, 9, 7, 15, 19, 23, 29, 31
                -> i = 0; j = 1;
                    -> for 0th element arr[i] = 2
                    -> element on gap 4 is arr[j] = 5
                    -> here(arr[i] < arr[j]) no swap & for previous as well
                    -> Arr: 2, 5, 9, 7, 15, 19, 23, 29, 31
                -> i++; j++;
                -> i = 1, j = 2
                    -> for 1th element arr[i] = 5
                    -> element on gap 4 is arr[j] = 9
                    -> here(arr[i] < arr[j]) no swap & for previous as well
                    -> Arr: 2, 5, 9, 7, 15, 19, 23, 29, 31
                -> i++; j++;
                -> i = 2, j = 3;
                    -> for 2th element arr[i] = 9
                    -> element on gap 4 is arr[j] = 7
                    -> here(arr[i] > arr[j]) swap
                    -> Arr: 2, 5, 7, 9, 15, 19, 23, 29, 31

                    -> check with previous with gap(1) arr[i - gap(1)]
                    -> arr[i - gap(1)] = arr[1] = 5
                    -> here(arr[i] < arr[i - gap(1)]) no swap and no need to go to previous element

                -> ..........
                -> Arr: 2, 5, 7, 9, 15, 19, 23, 29, 31
                => final Iteration:
                -> i++; j++;
                -> i = 7, j = 8;
                    -> for 3rd element arr[i] = 29
                    -> element on gap 4 is arr[j] = 31
                    -> here(arr[i] < arr[j]) no swap & no compare with previous element arr[i - gap(2)]
                    -> Arr: 2, 5, 7, 9, 15, 19, 23, 29, 31
                -> i++; j++;
                -> j > size of array so stop
            -> gap = N/16 = 0.5 = 0
            -> if gap == 0 stop pass
            -> Sorted array: 2, 5, 7, 9, 15, 19, 23, 29, 31
*/