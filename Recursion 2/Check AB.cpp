// Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
// a. The string begins with an 'a'
// b. Each 'a' is followed by nothing or an 'a' or "bb"
// c. Each "bb" is followed by nothing or an 'a'
// If all the rules are followed by the given string, return true otherwise return false.
// Input format :
// String S
// Output format :
// 'true' or 'false'
// Constraints :
// 1 <= |S| <= 1000
// where |S| represents length of string S.
// Sample Input 1 :
// abb
// Sample Output 1 :
// true
// Sample Input 2 :
// abababa
// Sample Output 2 :
// false
// Explanation for Sample Input 2
// In the above example, a is not followed by either "a" or "bb", instead it's followed by "b" which results in false to be returned.

bool check(char a[]){
    if(a[0] == '\0')
        return true;
    bool b;
    if(a[0]=='a' && (a[1]=='\0' || a[1]=='a'))
        b = check(a+1);
    else if(a[0]=='a' && (a[1]=='b' && a[2]=='b'))
        b = check(a+1);
    else if(a[0]=='b' && a[1]=='b' && (a[2]=='\0' || a[2]=='a'))
        b = check(a+2);
    else
        return false;
    return b;
}

bool checkAB(char input[]) {
    if(input[0] == '\0')
        return true;
    if(input[0]!='a')
        return false;
	// Write your code here
	check(input);
    
}



