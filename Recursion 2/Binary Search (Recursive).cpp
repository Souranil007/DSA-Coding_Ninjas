// Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
// Return -1 if x is not present in the given array.
// Note : If given array size is even, take first mid.
// Input format :

// Line 1 : Array size

// Line 2 : Array elements (separated by space)

// Line 3 : x (element to be searched)

// Sample Input :
// 6
// 2 3 4 5 6 8 
// 5 
// Sample Output:
// 3 

// input - input array
// size - length of input array
// element - value to be searched

int check(int a[], int low, int high, int element){
    if(low>high)
        return -1;
    int mid = (low+high)/2;
    if(element>a[mid]){
        return check(a, mid+1, high, element);
    }
    else if(element<a[mid]){
        return check(a, low, mid-1, element);
    }
    else{
        return mid;
    }
}

int binarySearch(int input[], int size, int element) {
    // Write your code here
	int low = 0;
    int high = size - 1;
    int ans = check(input, low, high, element);
    return ans;
}
