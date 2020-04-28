#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    int arr[N];

    cout<<"Enter sorted array: "<<endl;

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    int k = 0;
    cout<<"Enter sum: "<<endl;
    cin>>k;

    int *p1 = &arr[0];
    int *p2 = &arr[N-1];
    
    while(p1 < p2){
        if((*p1 + *p2) == k){
            break;
        }else if((*p1 + *p2) < k){
            p1++;
        }else{
            p2--;
        }
    }

    cout<<"Two elements are: "<<*p1<<" and "<<*p2<<endl;

    return 0;
}