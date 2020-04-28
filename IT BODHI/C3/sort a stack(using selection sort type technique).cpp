// complexity o(n2)  as n+n-1+n-2.......
#include<bits/stdc++.h>
#include<stack>
using namespace std;
stack <int> s1;
stack <int> s2;
int sortStack(int );
int main()
{
    cout<<"Enter stack size:"<<endl;
    int n;
    cin>>n;
    cout<<"Enter stack elements:"<<endl;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        s1.push(num);
    }
    sortStack(n);
    cout<<"Sorted stack is:"<<endl;
    while(!s1.empty()){
        cout<<s1.top()<<endl;
        s1.pop();
    }
}
int sortStack(int n){
    int maxI = -1;
    int j;
    for(int i=n-1;i>=0;i--){
        j=0;
        maxI=-1;
        while(j<=i){
            if(s1.top()>= maxI){
                maxI = s1.top();
            }
            s2.push(s1.top());
            s1.pop();
            j++;
        }
        s1.push(maxI);
        j=0;
        while(j<=i){
           // cout<<"op "<<s2.top();
            if(s2.top() != maxI){
                s1.push(s2.top());
                s2.pop();
            }else{
            s2.pop();
            }
            j++;
        }
    }
}
