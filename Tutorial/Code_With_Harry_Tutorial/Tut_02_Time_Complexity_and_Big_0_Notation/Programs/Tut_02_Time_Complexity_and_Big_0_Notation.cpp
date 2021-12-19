/*
# Space Complexcity:
The term Space Complexity is misused for Auxiliary Space at many places. Following are the correct definitions of Auxiliary Space and Space Complexity. 

Auxiliary Space is the extra space or temporary space used by an algorithm. 

Space Complexity of an algorithm is total space taken by the algorithm with respect to the input size. Space complexity includes both Auxiliary space and space used by input. 

For example, if we want to compare standard sorting algorithms on the basis of space, then Auxiliary Space would be a better criteria than Space Complexity. Merge Sort uses O(n) auxiliary space, Insertion sort and Heap Sort use O(1) auxiliary space. Space complexity of all these sorting algorithms is O(n) though. 

Space complexity is a parallel concept to time complexity. If we need to create an array of size n, this will require O(n) space. If we create a two dimensional array of size n*n, this will require O(n2) space.

*/