// complexity o(n2)  as n+n-1+n-2.......
#include<bits/stdc++.h>
#include<stack>
using namespace std;
stack <int> s1;
stack <int> s2;
int driver(int );
int main()
{
    cout<<"Enter stack size : "<<endl;
    int n;
    cin>>n;
    cout<<"Enter stack elements : "<<endl;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        s1.push(num);
    }
    driver(n);
    cout<<"Sorted stack is:"<<endl;
    while(!s1.empty()){
        cout<<s1.top()<<endl;
        s1.pop();
    }
}
int driver(int n){
    int pushed ;
    int temp1,temp,counter = 0;
    while(!s1.empty()){
            pushed=0;
            if(s2.size() == 0){
                temp = -1;
            }else{
                temp = s2.top();
            }
        if(s1.top() >= temp ){
            s2.push(s1.top());
            cout<<s1.top()<<endl;
            s1.pop();
            //counter++;
        }else{
            temp1 = s1.top();
            s1.pop();
            //counter++;
            while(!s2.empty()){
                //cout<<s2.top()<<endl;
                if(s2.top()>= temp1){
                  s1.push(s2.top());
                  s2.pop();
                }else{
                    s1.push(temp1);
                    temp1=-1;
                    pushed = 1;
                }
            }
            if(pushed == 0){
                s1.push(temp1);
            }
        }
    }
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
}
