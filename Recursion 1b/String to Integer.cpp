// Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
// Input format :
// Numeric string S (string, Eg. "1234")
// Output format :
// Corresponding integer N (int, Eg. 1234)
// Constraints :
// 0 < |S| <= 9
// where |S| represents length of string S.
// Sample Input 1 :
// 00001231
// Sample Output 1 :
// 1231
// Sample Input 2 :
// 12567
// Sample Output 2 :
// 12567

int strSize(char a[]){
    int cnt=0; 
    for(int i=0; a[i]!='\0'; i++)
        cnt++;
    return cnt;
}

int check(char b[], int last){
    if(last== 0)
		return b[last] - '0';
    
    int smallOutput = check(b, last-1);
    int a = b[last]-'0';
    return  smallOutput * 10 + a;
}
int stringToNumber(char input[]) {
    // Write your code here
	int size = strSize(input);
    return check(input, size-1); 
}


