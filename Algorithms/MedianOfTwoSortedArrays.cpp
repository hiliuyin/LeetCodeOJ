// Median of Two Sorted Arrays
// There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

// Consider there are N numbers in sorted array A,
// If N is odd, the median is (A[N/2]+A[N/2+1])/2;
// If N is even, the median is A[N/2].
//
// Just a exercise to study how to use heap, not the optimal method.

#define LEFT(i) (2*(i)+1)
#define RIGHT(i) (2*(i)+2)
#define PARENT(i) (((i)-1)/2)

void minHeapify(int A[], int i, int size)
{
    if (size <= 0) return;
    
    int smallest = i;
    if (LEFT(i) < size && A[LEFT(i)] < A[smallest])
        smallest = LEFT(i);
    if (RIGHT(i) < size && A[RIGHT(i)] < A[smallest])
        smallest = RIGHT(i);
    
    if (smallest != i)
    {
        std::swap(A[smallest], A[i]);
        minHeapify(A, smallest, size);
    }
}

int extractMin(int A[], int size)
{
    if (size <= 0) return -1;
    
    int min = A[0];
    std::swap(A[0], A[size-1]);

    minHeapify(A, 0, size-1);
    
    return min;
}

double findMedianSortedArrays(int A[], int m, int B[], int n)
{
    int mid = (m+n)/2;
    if ((m+n)%2 == 1)
        mid = (m+n+1)/2;
    double median = 0.0;
    
    if (m == 0 && n == 0)
    {
        return 0.0;
    }
    else if (m == 0 && n != 0)
    {
        if (n%2 == 0)
            median = ((double)B[n/2-1]+(double)B[n/2+1-1])/2;
        else
            median = B[(n+1)/2-1];
        return median;
    }
    else if (m != 0 && n == 0)
    {
        if (m%2 == 0)
            median = ((double)A[m/2-1]+(double)A[m/2+1-1])/2;
        else
            median = A[(m+1)/2-1];
        return median;
    }

    int i = m;
    int j = n;
    while (mid > 0 && i > 0 && j > 0)
    {
        if (A[0] < B[0])
        {
            median = extractMin(A, i);
            --i;
        }
        else
        {
            median = extractMin(B, j);
            --j;
        }
        --mid;
    }
    
    while (mid > 0)
    {
        if (i == 0)
        {
            median = extractMin(B, j);
            --j;
        }
        else
        {
            median = extractMin(A, i);
            --i;
        }
        mid--;
    }
    
    if ((m+n)%2 == 0)
    {
        if (i != 0 && j != 0)
        {
            median += min(A[0], B[0]);
        }
        else if (i == 0)
        {
            median += B[0];
        }
        else
        {
            median += A[0];
        }
        median = median/2;
    }
    
    return median;
}
