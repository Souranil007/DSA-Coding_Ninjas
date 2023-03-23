// Sort an array A using Merge Sort.
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
// 2 1 5 2 3
// Sample Output 2 :
// 1 2 2 3 5 

void merge(int *arr1, int *arr2, int size1, int size2, int *output, int n){
    int i=0;
    int j=0;
    int k=0;
    while(i<size1 && j<size2){
        if(arr1[i]<arr2[j]){
            output[k] = arr1[i];
            i++;
            k++;
        }
        else{
            output[k] = arr2[j];
            j++;
            k++;
        }
    }
    while(i<size1){
        output[k] = arr1[i];
        k++;
        i++;
    }
    while(j<size2){
        output[k] = arr2[j];
        k++;
        j++;
    }
}

void mergeSort(int input[], int size){
	// Write your code here
    if(size==0 || size==1)
        return;
    int *arr1 = new int[size/2];
    int size1 = size/2;
    int *arr2 = new int[size-size/2];
    int size2 = (size-size/2);
    for(int i=0; i<size1; i++){
        arr1[i] = input[i];
    }
    int k = 0;
    for(int i=size1; i<size; i++){
        arr2[k] = input[i];
        k++;
    }
    mergeSort(arr1, size1);
    mergeSort(arr2, size2);
    merge(arr1, arr2, size1, size2, input, size);
}
   	

