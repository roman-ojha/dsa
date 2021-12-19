/*
    #Insertion sort:
        |rs.6000|rs.9000|rs.10000|rs.12000|

        to insert = rs.8000
                            <------- check from this side
        |rs.6000|rs.9000|rs.10000|rs.12000|

        |rs.6000|rs.9000|rs.10000|        |rs.12000|

        |rs.6000|rs.9000|        |rs.10000|rs.12000|

        |rs.6000|       |rs.9000 |rs.10000|rs.12000|

        |rs.6000|rs.8000|rs.9000 |rs.10000|rs.12000|


    to sort:  7,2,91,77,3

    sorting Porcess:
        7|,2,91,77,3 -> sorted array of element 1 (7)

    -> 1st Pass (1 posible Comparision, 1 posible swap)
        2,7|,91,77,3 -> swap 7,2 (sorted array of element 2 (2,7))

    -> 2nd Pass (2 posible Comparision, 2 posible swap)
        2,7,91|,77,3 -> sorted array of element 3 (2,7,91)

    -> 3rd Pass (3 posible Comparision, 3 posible swap)
        2,7,  ,91|,3 
        2,7,77,91|,3 ->sorted array of element 4 (2,7,77,91)

    -> 4th Passs (4 posible Comparision, 4 posible swap)
        2,7,77, ,91| 
        2,7, ,77,91|
        2, ,7,77,91|
        2,3,7,77,91|

    Total Passes = n-1
    Length(n) = 5
    Total worst Case Posible Comparision:
        1+2+3+....(n-1) = n(n-1)/2 = O(n^2)
    Total best Case possible Comparision:
        TC = 1+1+1+1 = (n-1) = O(n)

    -> Stable? = This Algorighm is stable
    -> Adaptive? = This Algorithm is Adaptive 

    NOTE: 
        -> the intermideate result is not useful
*/