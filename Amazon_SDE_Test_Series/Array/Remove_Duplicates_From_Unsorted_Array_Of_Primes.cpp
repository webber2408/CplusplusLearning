/*
Remove duplicates in small prime array
https://www.geeksforgeeks.org/remove-duplicates-from-an-array-of-small-primes/

Given an array consisting of only prime numbers, remove all duplicate numbers from it. 
Note: Retain the first occurrence of the duplicate element.

Input:
First line of input contains number of testcases T. For each testcase, there will be two lines, first of which contains N, the size of array. The second line contains N space separated elements of the array. 

Output:
Print the resultant array with no duplicate elements. 

Your Task:
Complete the function removeDuplicate() that takes given array and N as input parameters and returns modified array which has no duplicates.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1<=T<=200
1<=N=1000
2<=A[i]<100

Example:
Sample Input:
1
6
2 2 3 3 7 5

Sample Output:
2 3 7 5

Explanation:
After removing the duplicate 2 and 3 we get 2 3 7 5.
*/

vector<int> removeDuplicate(vector<int>& arr, int n)
{
    unordered_map<int, int> hash_map;
    vector<int> result;
    for(int i=0;i<n;i++){
        if(hash_map.find(arr[i]) == hash_map.end()){
            hash_map[arr[i]] = 1;
            result.push_back(arr[i]);
        }
    }
    return result;
}

/*Efficient Code - If the element divides the product then it can be surely proved that the element 
has previously occurred in the array and hence the number will be rejected.*/
int removeDups(vector<int> &vect) 
{ 
   long long int prod = vect[0]; 
   int res_ind = 1; 
   for (int i=1; i<vect.size(); i++) 
   { 
       if (prod % vect[i] != 0) 
       { 
          vect[res_ind++]  = vect[i]; 
          prod *= vect[i]; 
       } 
   } 
   vect.erase(vect.begin()+res_ind, vect.end()); 
} 
