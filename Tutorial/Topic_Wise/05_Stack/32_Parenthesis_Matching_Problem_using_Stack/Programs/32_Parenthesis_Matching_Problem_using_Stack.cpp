/*
1) A=((3*2)-1(8-2)) => this is a valid expression of parenthesis is matching in this expression

2) A=1-3)*4(8 ; => in this expression parenthesis is not maching so this is the  problem
but in 2nd case computer are not smart like human so they don't know that is this valid or not
so to check this expression what we can do is

if '(' -> Push into the stack
if ')' -> Pop out of the stack

Condition for a balanced expression
1) while popping stack should not underflow => if it happens -> unbalanced expression
2) while end of expression , the stack must be empty 


*) 7-(8(3 * 9)+ 11 + 12) -8
    a) How many push pop operation?
        -> 4 operation
    b) Time Complexity?
        -> worst : O(n)
        -> best case when the first character is closing bractet ")", it will directly return unbalanced and it will not have to check the remaining  . Time complexity of best case is O(1)
*/