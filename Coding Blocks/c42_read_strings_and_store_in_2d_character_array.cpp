#include<iostream>
using namespace std;

int main(){

    char a[100][1000];

    int n;
    cin>>n;

    cin.get(); //to encorporate an enter 

    for(int i = 0; i < n; i++){
        cin.getline(a[i], 1000); //Default delimiter is \n
    }

    //Print
    for(int i=0; i<n; i++){
        cout<<a[i]<<endl; //a[i] is our row pointer
    }
    
    return 0;
}