/*
https://www.geeksforgeeks.org/maximum-sum-path-across-two-arrays/
Based on Merge Sort
*/
#include<iostream>
using namespace std;

// Utility function to find maximum of two integers
int max(int x, int y) { return (x > y)? x : y; }
int maxPathSum(int arr1[], int arr2[], int m, int n){
    int i=0, j=0, sum1=0, sum2=0, result=0;
    
    while(i<m && j<n){
        if(arr1[i] < arr2[j])
            sum1 += arr1[i++];
        else if(arr1[i] > arr2[j])
            sum2 += arr2[j++];
        else{
            result += max(sum1, sum2);
            sum1 = sum2 = 0;
            while(i<m && j<n && arr1[i] == arr2[j]){
                result += arr1[i++];
                j++;
            }
        }
    }

    while(i<m)
        sum1 += arr1[i++];
    while(j<n)
        sum2 += arr2[j++];

    result += max(sum1, sum2);

    return result;
}
// Driver program to test above function
int main()
{
    int ar1[]  = {2, 3, 7, 10, 12, 15, 30, 34};
    int ar2[] =  {1, 5, 7, 8, 10, 15, 16, 19};
    int m = sizeof(ar1)/sizeof(ar1[0]);
    int n = sizeof(ar2)/sizeof(ar2[0]);
    cout << "Maximum sum path is " 
         << maxPathSum(ar1, ar2, m, n) <<endl;
    return 0;
}
