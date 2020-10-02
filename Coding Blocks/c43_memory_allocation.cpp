#include<bits/stdc++.h>
using namespace std;

int main(){

    //Allocation + Deallocation = Compiler
    int b[100] = {0};
    cout<<sizeof(b)<<endl;
    cout<<b<<endl; //symbol table

    //Dynamic Memory Allocation
    int n;
    cin>>n;
    int *a = new int[n]{0};
    cout<<sizeof(a)<<endl;
    cout<<a<<endl;

    return 0;
}