/*
Sorted subsequence of size 3
https://www.geeksforgeeks.org/find-a-sorted-subsequence-of-size-3-in-linear-time/

Given an array A of N integers, find any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the size of the array A in the next line are N space-separated values of the array A.

Output:
For each test case in a new line, the output will be 1 if the sub-sequence returned by the function is present in array A else 0. If the sub-sequence returned by the function is not in the format as mentioned then the output will be -1.

User Task:
Your task is to complete the function find3Numbers which finds any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k. You need to return them as a vector, if no such element is present then return the empty vector of size 0.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= A[i] <= 106, for each valid i

Example:
Input:
2
5
1 2 1 1 3
3
1 1 3
Output:
1
0

Explanation:
Test case 1: a sub-sequence 1 2 3 exist.
Test case 2: no such sub-sequence exist.
*/
vector<int> find3Numbers(vector<int> arr, int n) {
    int* smaller = new int[n]{-1};
    int* greater = new int[n]{-1};

    smaller[0] = -1;
    int min = 0;
    for(int i=1;i<n;i++){
        if(arr[i] <= arr[min]){
            min = i;
            smaller[i] = -1;
        }else{
            smaller[i] = min;
        }
    }
    
    greater[n-1] = -1;
    int max = n-1;
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] >= arr[max]){
            max = i;
            greater[i] = -1;
        }else{
            greater[i] = max;
        }
    }
    
    vector<int> result;
    for(int i=0;i<n;i++){
        if(smaller[i] != -1 && greater[i] != -1){
            result.push_back(arr[smaller[i]]);
            result.push_back(arr[i]);
            result.push_back(arr[greater[i]]);
            return result;
        }
    }
    delete[] smaller;
    delete[] greater;
    return result;
}