/*Take N (number of rows), print the following pattern (for N = 5)
1
2 2
3 0 3
4 0 0 4
5 0 0 0 5

Input Format
Constraints
0 < N < 100

Output Format
Sample Input
5
Sample Output
1  
2	2  
3	0	3    
4	0	0	4  
5	0	0	0	5
Explanation
Each number is separated from other by a tab.If row number is n (>1), total character is n. First and last character is n and rest are 0.
*/
#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;

    cout<<1<<endl;
    for(int i=2;i<=N;i++){
        int j=i;
        cout<<i<<"\t";
        while(j-2>0){
            cout<<0<<"\t";
            j--;
        }
        cout<<i<<endl;
    }

    return 0;
}