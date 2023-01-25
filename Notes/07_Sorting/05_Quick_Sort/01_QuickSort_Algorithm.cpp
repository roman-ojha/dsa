/*
    # Quick Sort:

    arr1 according to height:
    arr1[5]={161,175,152,180,178};

    1) partision:
        pivot = 161

        <---- lesser then or equal to 'pivot' at left side
        ----> greager then 'pivot' at right side
        {161,175,152,180,178}
              |           |
              i=1-->    <--j=4
        is arr1[i]>arr1['pivot'], yess i=1
        is arr1[j]<=arr1['pivot'], no j--, j=3;
        is arr1[j]<=arr1['pivot'], no j--, j=2;
        is arr1[j]<=arr1['pivot'], yes j=2;
        swap(arr1[i],arr1[j])
        {161,152,175,180,178}
              |    |
             i=1  j=2

        i++;j--;
        is arr1[i]>arr1['pivot'], yess i=2 ,j=1
        j<=i so, swap(arr1['pivot'],arr1[j]) (after doing this lesser then 'pivot' will come to front of array and grater to right)
        'pivot' index = 1
        {161,|152|,175,180,178}
        -----  |    ----------
          |    |         |
unsortedArray sorted  unsorted array

    2) Partision:
        now, pivot = 175 (first key of the unsorted array)

        do the same task again an again and again..................


    # Partitioning Process:
        1) i=low
        2) j=high
        3) pivot = low
        4) i++ until element --> pivot is found
        5) j-- until element <= pivot is found
        6) Swap A[i] & A[j] and repeat 4 & 5 until j<=i
        7) swap pivot & A[j]
*/
