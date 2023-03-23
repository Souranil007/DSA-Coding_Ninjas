// Sort an array A using Quick Sort.
// Change in the input array itself. So no need to return or print anything.


// Input format :
// Line 1 : Integer n i.e. Array size
// Line 2 : Array elements (separated by space)
// Output format :
// Array elements in increasing order (separated by space)
// Constraints :
// 1 <= n <= 10^3
// Sample Input 1 :
// 6 
// 2 6 8 5 4 3
// Sample Output 1 :
// 2 3 4 5 6 8
// Sample Input 2 :
// 5
// 1 5 2 7 3
// Sample Output 2 :
// 1 2 3 5 7 

/*
	To apply the method explained in the hint video, we have to add two more parameters in the function call. This can be done by calling a helper function from given function. The helper function can have three parameters: array, start index, end index.  
	
	Skeleton code to achieve this:
	#include <iostream>
	using namespace std;
	
	void quickSort(int input[], int start, int end)
	{
    		// your code goes here 
	}
	void quickSort(int input[], int size)
	{
    		quickSort(input, 0, size - 1);
	}
		
*/
int partition(int a[], int low, int high){
	int pivot = a[low];
    int i = low+1; 
    int j = high;
    int temp;
    
    do{
        while(a[i]<=pivot){
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }while(i<j);
    
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quickSortCheck(int arr[], int start, int end){
    if(start<=end){
        int partitionIndex = partition(arr, start, end);
        quickSortCheck(arr, start, partitionIndex-1);
        quickSortCheck(arr, partitionIndex+1, end);
    }
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    if(size==0 || size==1)
        return;
	int start = 0;
    int end = size-1;
    
    quickSortCheck(input, start, end);
}
