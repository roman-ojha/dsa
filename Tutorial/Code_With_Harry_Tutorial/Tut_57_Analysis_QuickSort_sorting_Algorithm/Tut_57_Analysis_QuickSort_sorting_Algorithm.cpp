/*
    # Worst Case:
        -> Already sorted Elemnets
        -> 1,2,4,8,12

        No of patition: (n-1)
        No. of Comparision in patition :
            = Some linear function of n
            =k1n+k2
            T=(n-1)*k1n+k2
            T=O(n^2)

    # Best case:
        -> O(nlogn)
        -> partition for 16 element 
                        16  --> 1*T(n)
                       /  \
                      /    \
                     /      \
                    /        \
                   8         7 --> 2*T(n/2)
                  / \       / \
                 /   \     3   3   --> 2^2 *T(n/n^2)
                4     3   / \ / \
               / \   / \ 1   11  1
              /   \ 1   1
             2     1

            Partition Time:
                T(n) =K1h+k2
                
            Total time=(k1n)+2(k1*n/2)+2^2(k1*n/2^2)+ .... + h (hight of tree)
            = h*k1n+k ==> O(nlogn)
        
    -> Stable? = Quick sort algorighm is not stable
    -> Quick sort is inplace Algorithm

*/