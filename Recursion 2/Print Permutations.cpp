// Given an input string (STR), print all possible permutations of the input string.
// Note:
// The input string may contain the same characters, so there will also be the same permutations.
// The order of permutations doesn’t matter.
// Input Format:
// The only input line contains a string (STR) of alphabets in lower case
// Output Format:
// Print each permutations in a new line
// Constraint:
// 1<=length of STR<=8
// Time Limit: 1sec
// Sample Input 1:
// cba
// Sample Output 1:
// abc
// acb
// bac
// bca
// cab
// cba

#include <iostream>
#include <string>
using namespace std;

void permute(string a, int left, int right){
    if(left==right){
        cout<<a<<endl;
    }
    else{
        for(int i=left; i<=right; i++){
            swap(a[left], a[i]);
            permute(a, left+1, right);
            swap(a[left], a[i]);
        }
    }
}

void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    permute(input, 0, input.size()-1);
}
