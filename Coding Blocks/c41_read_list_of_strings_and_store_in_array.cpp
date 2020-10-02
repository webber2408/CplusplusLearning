#include<iostream>
using namespace std;

int main(){
    char a[1000][1000];

    int n;
    cin>>n;

    cin.get(); //to catch `Enter`

    for(int i=0;i<n;i++){
        cin.getline(a[i], 1000); //(Where to place, Stream size)
    }

    //Print out strings
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}