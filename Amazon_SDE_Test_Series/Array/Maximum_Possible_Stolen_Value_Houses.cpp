/*
Stickler Thief
https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/
https://practice.geeksforgeeks.org/editorial.php?pid=701417&track=amazon-arrays&batchId=192

Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present in it.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each test case contains an integer n which denotes the number of houses. Next line contains space separated numbers denoting the amount of money in each house.

Output:
For each testcase, in a newline, print an integer which denotes the maximum amount he can take home.

Expected Time Complexity: O(N).
Expected Space Complexity: O(N).

Constraints:
1 <= T <= 200
1 <= n <= 104
1 <= a[i] <= 104

Example:
Input:
2
6
5 5 10 100 10 5
3
1 2 3
Output:
110
4

Explanation:
Testcase1:
5+100+5=110
Testcase2:
1+3=4
*/
ll max(ll a, ll b){
    return a > b? a : b;
}
ll FindMaxSum(ll arr[], ll n)
{
    if(n == 0)
        return 0;
    
    int v1 = arr[0];
    if(n == 1)
        return v1;
    
    int v2 = max(v1, arr[1]);
    if(n == 2)
        return v2;
        
    int max_value = 0;
    for(int i=2; i<n; i++){
        max_value = max(arr[i] + v1, v2);
        v1 = v2;
        v2 = max_value;
    }
    
    return max_value;
}