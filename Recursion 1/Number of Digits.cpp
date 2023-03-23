// Given the number 'n', find out and return the number of digits present in a number .
// Input Format :
// Integer n
// Output Format :
// Count of digits
// Constraints :
// 1 <= n <= 10^6
// Sample Input 1 :
//  156
// Sample Output 1 :
// 3
// Sample Input 2 :
//  7
// Sample Output 2 :
// 1

int count(int n){
    //write your code here
    static int cnt=0;
    if(n!=0){
        cnt++;
        count(n/10);
    }
    return cnt;
}
