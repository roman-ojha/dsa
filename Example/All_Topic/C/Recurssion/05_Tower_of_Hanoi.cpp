/*
    => Tower of Hanoi is a mathematical puzzle where we have three rods and n disks
    => The objective of the puzzle is to move the entire stack to another rod.
    => Moving of disks should follow the following rules:
        1) Only one disk can be moved at a time
        2) A disk can only be moved if it is the uppermost disk on a stack
        3) No disk may be placed on top of a smaller disk.

    => Step take in this operation is: (2^n - 1) , where n = number of disk
*/

#include <iostream>
#include <stdio.h>
using namespace std;

void towerOfHanoi(int n, char s, char a, char d)
{
    // n = Number of disks to be moved
    // s = Source/ rod where disk is present at inital
    // a = Auxiliary/ rod in between
    // d = Destination/ rod where disk need to moved in final

    // now, we can divide our task into simpler subtasks
    if (n == 1)
    {
        // if there is one disk the we will move 1 disk from sorce to destination
        printf("\n Move disk 1 from rod %c to rod %c", s, d);
        return;
    }
    // Other wise 'n-1' disk will be moved from source to auxiliary keeping destination as intermediate
    towerOfHanoi(n - 1, s, d, a);
    printf("\n Move disk %d from rod %c to rod %c", n, s, d);
    // now we can easyly move last disk(nth disk) which is in sorce to distination
    towerOfHanoi(n - 1, a, s, d);
    // so now the 'n-1' disk which were in the auxiliary to the distination keeping source as intermediate
}

int main()
{
    int n = 4;
    // n =  Number of disks
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}