/*
    *) Job Sequencing:
        -> EX:
            J: j1 j2 j3 j4 j5 j6
            D: 5  3  3  2  4  2
            P: 15 10 12 20 8  5
        -> Sort with profit wise
            J: j4 j1 j3 j2 j5 j6
            D: 2  5  3  3  4  2
            P: 20 15 12 10 8  5

        -> With Deadline Sequence:
            0  1  2  3  4  5
            |  |  |  |  |  |

        => For J4:
            -> because j4 have maximum profit we will try to place into the sequence
            -> because j4 have deadline 2 it means that we can complete this job upto deadline 2
            -> so we have to place the j4 as far as possible upto the given deadline
            -> for now we can place it into sequence 2
            -> but if sequence 2 had already filled then we must have to place before 2 which is 1 sequence
            -> but now we can place into 2
                0   1   2    3   4   5
                |   | j4 |   |   |   |

            => Profit : 20

        => For j1:
            -> j1 have second highest profit so we will try to place it into sequence
            -> j1 have deadline 5
            -> we can place j1 in any empty job sequence but we will place j1 as far as possible
            -> place j1 upto 5 sequence
                0   1    2   3   4    5
                |   | j4 |   |   | j1 |
            => Profit: 20 + 15 = 35

        => For j3:
            -> j3 have deadline 3
            -> place j3 into 3 sequence
                0   1    2    3   4    5
                |   | j4 | j3 |   | j1 |
            => Profit: 35 + 12 = 47

        => For j2:
            -> j2 have deadline 3
            -> place j2 as far as upto 3rd sequence
            -> but 2nd & 3rd sequence is already fill
            -> so we can only place j2 in 1st sequence
                0    1    2    3   4    5
                | j2 | j4 | j3 |   | j1 |
            => Profit: 47 + 10 = 57

        => For j5:
            -> j5 have deadline 4
            -> place j4 as far as upto 4th sequence
            -> because there is only one place left upto 4th sequence which is 4th sequence
            -> placing j5 into 4th sequence
                0    1    2    3    4    5
                | j2 | j4 | j3 | j5 | j1 |
            => Profit: 57 + 8 = 65

        => Therefor:
            -> Job sequence with maximum profit is:
                -> J2, J4, J3, J5, J1
            => with maximum profit of: 65
*/