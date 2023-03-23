// You have made a smartphone app and want to set its subscription price such that the profit earned is maximised. There are certain users who will subscribe to your app only if their budget is greater than or equal to your price.
// You will be provided with a list of size N having budgets of subscribers and you need to return the maximum profit that you can earn.
// Lets say you decide that price of your app is Rs. x and there are N number of subscribers. So maximum profit you can earn is :
//  m * x
// where m is total number of subscribers whose budget is greater than or equal to x.
// Input format :
// Line 1 : N (No. of subscribers)
// Line 2 : Budget of subscribers (separated by space)
// Output Format :
//  Maximum profit
// Constraints :
// 1 <= N <= 10^6
// 1 <=budget[i]<=9999
// Sample Input 1 :
// 4
// 30 20 53 14
// Sample Output 1 :
// 60
// Sample Output 1 Explanation :
// Price of your app should be Rs. 20 or Rs. 30. For both prices, you can get the profit Rs. 60.
// Sample Input 2 :
// 5
// 34 78 90 15 67
// Sample Output 2 :
// 201
// Sample Output 2 Explanation :
// Price of your app should be Rs. 67. You can get the profit Rs. 201 (i.e. 3 * 67).

int partition(int budget[], int left, int right){
    for(int i=left; i<right; i++){
        if(budget[i] <= budget[right]){
            if(i!=left){
                int temp = budget[i];
                budget[i] = budget[left];
                budget[left] = temp;
            }
            left++;
        }
    }
    if(left!=right){
        int temp = budget[left];
        budget[left] = budget[right];
        budget[right] = temp;
    }
    return left;
}


void quickSort(int budget[], int left, int right){
    if(left<right){
        int partitionIndex = partition(budget, left, right);
        quickSort(budget, left, partitionIndex-1);
        quickSort(budget, partitionIndex+1, right);
    }
}

int maximumProfit(int budget[], int n) {
    // Write your code here
    quickSort(budget, 0, n-1);
    int maxProfit = 0;
    for(int i=0; i<n; i++){
        maxProfit = max(maxProfit, budget[i]*(n-i));
    }
    return maxProfit;
}
