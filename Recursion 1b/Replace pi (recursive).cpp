// Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
// Constraints :
// 1 <= |S| <= 50
// where |S| represents the length of string S. 
// Sample Input 1 :
// xpix
// Sample Output :
// x3.14x
// Sample Input 2 :
// pipi
// Sample Output :
// 3.143.14
// Sample Input 3 :
// pip
// Sample Output :
// 3.14p
// Constraints:-
// 1<=|S|<=50

// Change in the given string itself. So no need to return or print anything
int strSize(char a[]){
    int cnt=0;
    for(int i=0; a[i]!='\0'; i++)
        cnt++;
    return cnt;
}

void check(char b[], int len){
    if(b[0] =='\0')
        return;
    if(b[0]=='p' && b[1]=='i'){
        for(int k=len; k>=2; k--){
            b[k+2] = b[k];
        }
        b[0] = '3';
        b[1] = '.';
        b[2] = '1';
        b[3] = '4';
    check(b+4, len);
    }
    else{
        check(b+1, len);
    }
}
void replacePi(char input[]) {
	// Write your code here
	int size = strSize(input);
    check(input, size);
}


