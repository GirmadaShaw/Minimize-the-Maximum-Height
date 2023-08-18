/*
Given the heights of N towers and a value of K, Either increase or decrease the height of every tower by K 
(only once) where K > 0. After modifications, the task is to
minimize the difference between the heights of the longest and the shortest tower and output its difference.
Input: arr[] = {1, 15, 10}, k = 6
Output:  Maximum difference is 5.
Input: arr[] = {1, 5, 15, 10}, k = 3   
Output: Maximum difference is 8.
*/

#include <iostream>
#include <algorithm>

using namespace std;
 
// User function Template
int getMinDiff(int arr[], int n, int k)
{
    std :: sort(arr, arr + n);
 
    // Maximum possible height difference
    int ans = arr[n - 1] - arr[0];
 
    int tempmin, tempmax;
    tempmin = arr[0];
    tempmax = arr[n - 1];
 
    for (int i = 1; i < n; i++) {
 
        // If on subtracting k we got
        // negative then continue
        if (arr[i] - k < 0)
            continue;
 
        // Minimum element when we
        // add k to whole array
        tempmin = min(arr[0] + k, arr[i] - k);
 
        // Maximum element when we
        // subtract k from whole array
        tempmax = max(arr[i - 1] + k, arr[n - 1] - k);
 
        ans = min(ans, tempmax - tempmin);
    }
    return ans;
}
 
// Driver Code Starts
int main()
{
 
    
    //int arr[] = { 7, 4, 8, 8, 8, 9 }, k = 6 ;
    //int arr[] = {1, 15, 10}, k = 6 ;
    int arr[] = {1, 5, 15, 10}, k = 3  ;
    int n = sizeof(arr)/sizeof(int) ;
 
    // Function Call
    int ans = getMinDiff(arr, n, k);
    cout << "Required answer is: " << ans;
}