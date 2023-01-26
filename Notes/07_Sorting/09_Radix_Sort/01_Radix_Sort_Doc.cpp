/*
    *) Radix sort:
        -> no comparision would be done to sort.
        -> data will get sorted digit by digit.
        => Place & face value:
            -> 421
            -> place value of 1 is 1's
            -> place value of 2 is 10's
            -> place value of 3 is 100's
            -> face value of 1's is 1
            -> face value of 10's is 2
            -> face value of 100's is 4
            => 421:
                -> starting sorting from lest significant digit then to the most significant digit
                -> from 1's to 100's
        => EX:
            -> arr: 15, 1, 321, 10, 802, 2, 123, 90, 109, 11
            -> Max number = 802 with max digit of 3
            -> make all digit a 3 digit number by placing 0 at the first place
            -> arr: 015, 001, 321, 010, 802, 002, 123, 090, 109, 011
            -> because we have 9 digit in number we will create a 10 size bucket from 0-9
            -> if we are sorting string then we will create the bucket of 0-25
            => 1st pass:
                -> in 1st pass we will put element according to the last digit from element number
                -> 0th index val = 015, last digit from this val = 5
                -> in bucket 5: 015
                -> do this for all the the element and put it into bucket
                -> removing one by one data from all the buckets and place into arr one by one
                -> after 1st pass:
                -> arr: 010, 090, 001, 321, 011, 802, 002, 123, 015, 109
            => 2nd pass:
                -> place into bucket according to 2nd last digit.
                -> 0th index val = 010, 2nd last digit is 1
                -> in bucket 1: 010
                -> do this for all the element and put it into bucket.
                -> removing one by one data from all the buckets and place into arr one by one
                -> after 2nd pass:
                -> arr: 001, 802, 002, 109, 010, 011, 015, 321, 123, 090
            => 2nd pass:
                -> place into bucket according to 2nd last digit.
                -> 0th index val = 010, 2nd last digit is 1
                -> in bucket 1: 010
                -> do this for all the element and put it into bucket.
                -> removing one by one data from all the buckets and place into arr one by one
                -> after 2nd pass:
                -> arr: 001, 802, 002, 109, 010, 011, 015, 321, 123, 090
                -> here lsb(least significant bit) is got sorted
            => 3rd pass:
                -> place into bucket according to 3nd last digit or first digit.
                -> 0th index val = 010, 3rd last digit is 0
                -> in bucket 0: 010
                -> do this for all the element and put it into bucket.
                -> removing one by one data from all the buckets and place into arr one by one
                -> after 3rd pass:
                -> arr: 001, 002, 010, 011, 015, 090, 109, 123, 321, 802
            => after 3rd pass we got the sorted array
                -> arr: 1, 2, 10, 11, 15, 90, 109, 123, 321, 802

            => Number of pass:
                -> maximum value '802' digit 3
                -> so number of pass would be 3

        => it use a Count sort as subroutine.

        => Time complexity:
            -> O(d * (n + b))
            -> d: digit
            -> n: size of array
            -> b: bucket size, base size
                -> base size: for number 9, for alphabets 26

        => More: https://www.geeksforgeeks.org/radix-sort/
*/