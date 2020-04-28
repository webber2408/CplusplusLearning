/*
Take N (number of rows), print the following pattern (for N = 4).

                       1           1
                       1 2       2 1  
                       1 2 3   3 2 1
                       1 2 3 4 3 2 1   
Input Format
Constraints
0 < N < 10

Output Format
Sample Input
4
Sample Output
1						1
1	2				2	1
1	2	3		3	2	1
1	2	3	4	3	2	1
Explanation
Each number is separated from other by a tab.
*/
#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;

    for(int i=1;i<=N;i++){
        int j=1;
        while(j<=i){
            cout<<j<<"\t";
            j++;
        }
        for(int k=1;k<=2*N-1-2*i;k++){
            cout<<" "<<"\t";
        }
        j--;
        while(j>0){
            if(j!=N){
                cout<<j<<"\t";
            }
            j--;
        }
        cout<<endl;
    }
    return 0;
}