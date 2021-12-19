/*
1) A=((3*2)-1(8-2)) => this is a valid expression of parenthesis is matching in this expression

2) A=1-3)*4(8 ; => in this expression parenthesis is not maching so this is the  problem
but in 2nd case computer are not smart like human so they don't know that is this valid of not
so to check this expression what we can do is

if '(' -> Push into the stack
if ')' -> Pop out of the stack

Condition for a balanced expression
1) while popping stack should not underflow => if it happens -> unbalanced expression
2) while end of expression , the stack must be empty 

*/