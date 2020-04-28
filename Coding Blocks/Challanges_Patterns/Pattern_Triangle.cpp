/*
Take N (number of rows), print the following pattern (for N = 4).

                       1 
                     2 3 2
                   3 4 5 4 3
                 4 5 6 7 6 5 4
Input Format
Constraints
0 < N < 10

Output Format
Sample Input
4
Sample Output
            1
		2	3	2
	3	4	5	4	3
4	5	6	7	6	5	4
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
        while(j<=N-i){
            cout<<" "<<"\t";
            j++;
        }
        j=i;
        int count = i;
        while(j>0){
            cout<<count++<<"\t";
            j--;
        }
        count-=2;
        j=i-1;
        while(j>0){
            cout<<count--<<"\t";
            j--;
        }
        cout<<endl;
    }
    return 0;
}