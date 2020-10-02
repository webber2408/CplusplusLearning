#include<iostream>
#include<vector>
using namespace std;

bool binary_search(vector<int> vec, int n, int key){
    int s = 0;
    int e = n-1;
    int m;
    while(s<=e){
        m = (s+e)/2;

        if(vec[m]==key){
            cout<<"Element found at position "<<m<<endl;
            return true;
        }else if(vec[m] > key){
            e = m-1;
        }else{
            s = m+1;
        }
    }
    return false;
}

int main(){
    int N;
    cin>>N;
    cout<<"Enter sorted array elements"<<endl;
    vector<int> vec;

    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        vec.push_back(num);
    }

    cout<<"Enter key:"<<endl;
    int key;
    cin>>key;

    if(!binary_search(vec, N, key)){
        cout<<"Element not present in the array!"<<endl;
    }

    return 0;
}