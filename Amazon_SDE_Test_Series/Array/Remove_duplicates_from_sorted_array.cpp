/*
Remove duplicate elements from sorted Array
Given a sorted array A of size N. The function remove_duplicate takes two arguments . The first argument is the sorted array A[ ] and the second argument is 'N' the size of the array and returns the size of the new converted array A[ ] with no duplicate element.

Input Format:
The first line of input contains T denoting the no of test cases . Then T test cases follow . The first line of each test case contains an Integer N and the next line contains N space separated values of the array A[ ] .

Output Format:
For each test case output will be the transformed array with no duplicates.

Your Task:
Your task to complete the function remove_duplicate which removes the duplicate  elements from the array .

Constraints:
1 <= T <= 100
1 <= N <= 104
1 <= A[ ] <= 106

Example:
Input  (To be used only for expected output) :
2
5
2 2 2 2 2 
3
1 2 2
Output
2
1 2

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> getUniqueArray(int arr[], int N){
    vector<int> result;
    int i=0;
    while(i<N-1){
        if(arr[i] != arr[i+1])
            result.push_back(arr[i]);
        i++;
    }
    if(result[result.size()-1] != arr[N-1]){
        result.push_back(arr[N-1]);
    }
    return result;
}
int getUniqueArrayInPlace(int arr[], int N){
    if(N <= 1){
        return N;
    }
    int j=0, i=1, count=1;
    while(i<N){
        if(arr[i] == arr[j] && count == 1){
            arr[++j] = arr[i];
            count++;
        }else if(arr[i] != arr[j]){
            arr[++j] = arr[i];
            count = 1;
        }
        i++;
    }
    return j+1;
}
int main(){
    int cases;
    cin>>cases;

    for(int i=0;i<cases;i++){
        int N;
        cin>>N;
        int arr[N];
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }
        vector<int> result = getUniqueArray(arr, N);
        for(int i=0;i<result.size();i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}