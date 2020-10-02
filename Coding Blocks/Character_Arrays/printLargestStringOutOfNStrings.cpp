#include<iostream>
#include<cstring>
using namespace std;

int main(){

    int N;
    cin>>N;
    cin.get(); // Need to consume the \n after inputting N
    char current[1000], largest[1000] = {};

    for(int i=0; i<N; i++){
        cin.getline(current, 1000);
        if(strlen(current) > strlen(largest)){
            strcpy(largest, current);
        }
    }

    cout<<largest<<endl;

    return 0;
}