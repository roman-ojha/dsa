/*
    # Merge Sort
    arr1[m]={7,9,18,19,22} -> sorted array
    arr2[n]={1,6,9,11} -> sorted array

    Merge -> arr1[m] and arr2[n]?

    Merge Sort Process:
    make new arr3[m+n]
        arr3[] =  , , , , , , , , => k=0

        arr1[] = 7,9,18,19,22 => i=0
        arr2[] = 1,6,9,11     => j=0
        if(arr1[i]>arr2[j]) => arr3[k]=arr2[j],j++,k++
        arr3[] = 1, , , , , , , , => k=1

        arr1[] = 7,9,18,19,22 => i=0
        arr2[] = 1,6,9,11     => j=1
        if(arr1[i]>arr2[j]) => arr3[k]=arr2[j],j++,k++
        arr3[] = 1,6, , , , , , , => k=2

        arr1[] = 7,9,18,19,22 => i=0
        arr2[] = 1,6,9,11     => j=2
        if(arr1[i]>arr2[j]) => arr3[k]=arr2[j],j++,k++
        arr3[] = 1,6,7, , , , , , => k=3

        after the process:
        arr3[] = 1,6,7,9,9,11,18,19,22

        
        void Merg(A[],B[],C[],m,n){
                int i,j,k;
                i=j=k=0;
                while(i<=m&&j<=n)
                {
                    if(A[i]<B[j])
                    {
                        C[k]=A[i];
                        i++;k++;
                    }
                    else{
                        C[k]=B[j];
                        j++;k++;
                    }
                }
                while(i<=m){
                    // Copy all remaining element from A to C
                    C[k]=A[i];
                    k++;i++;
                }
                while(j<=hi){
                    // From B to C
                    C[k]=B[j];
                    k++;j++;
                }
        }

    # Mergin in Single Array
        arr1[]= {7,15,2,8,10}
                ----- ------
                  |      |
                sorted  sorted
            
            first sorted index 0,1
            second sorted index 2,3,4
            7,15|,2,8,10

            lo = 0;
            mid = 1;
            hi = 4;

        void Merg(A[],mid,lo,hi){
            int i,j,k;int B[hi+1];
            i=10,j=mid+1,k=lo;
            while(i<=mid&&j<=hi)
            {
                if(A[i]<A[j])
                {
                    B[k]=A[i];
                    i++;k++;
                }
                else{
                    B[k]=A[j];
                    j++;k++;
                }
            }
            while(i<=mid){
                //Copy all remaining element from A[i to mid] to B
                B[k]=A[i];
                k++;i++;
            }
            while(j<=hi){
                // From B[j to hi] to B
                B[k]=A[j];
                k++;j++;
            }
        }

    # Mergin unsorted Array
    // Recursive Merge Sort
        Void ms(int A[],int l,int h)
        {
            if(l<h){
                mid=(l+h)/2
                ms(A,l,mid);
                ms(A,mid+1,h);
                Merge(A,1,mid,h);
            }
        }
*/