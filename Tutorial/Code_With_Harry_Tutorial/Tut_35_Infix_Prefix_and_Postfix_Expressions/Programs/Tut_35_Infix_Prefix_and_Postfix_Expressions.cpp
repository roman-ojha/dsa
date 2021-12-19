/*
Notation to wirte an expression
1) Infix = a+b , a-b , p/q , x-4
            Operand <operator> Operand
2) Prefix  = +ab , -pq ,-xy , *pb
            <operator> <Operand 1> <Operand 2>
3) Postfix = ab+ , xy- , pv*
            <Operand 1> <Operand 2> <Operator>

*/

/*
Expression in infix:
                    A*(B+C)*D => A=1, B=2, C=3, D=4
                ->  A*5*D
                ->  5*D
                ->  20
Expression in Postfix:
                    ABC+*D* => A=1, B=2, C=3, D=4
                ->  A5*D*
                ->  5D*
                ->  20
Expression in prefix: 
                    *A*+BCD

                    
*/

/*
Q1) x-y*z to prefix and postfix ?
=>  this will worked according to the presedence of the operator and associativity of the operator
    1) Prefix
        Step 1-> parenthesize the expression
            (x-(y*z))
            (x-[*yz])
            (-x[*yz])
        so, -x*yz
    2) Postfix
        Step 1-> parenthesize the expression
            (x-(y*z))
            (x-[yz]*)
            (xyz*-)
        so, xyz*-
*/