// Check whether a given String S is a palindrome using recursion. Return true or false.
// Input Format :
// String S
// Output Format :
// 'true' or 'false'
// Constraints :
// 0 <= |S| <= 1000
// where |S| represents length of string S.
// Sample Input 1 :
// racecar
// Sample Output 1:
// true
// Sample Input 2 :
// ninja
// Sample Output 2:
// false


bool checkPalindrome(char input[]) {
    static int a=0;
    int c=0;
    
    while(input[c]!='\0'){
        c++;
    }
    static int d=c;
    
    if(input[a]==input[d-1] && a<d){
        a++;
        d--;
        
        return checkPalindrome(input);
    }
    else{
        if(a<d)
            return false;
        else
            return true;
    }
}
	
