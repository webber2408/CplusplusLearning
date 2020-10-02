#include<iostream>
#include<climits>
using namespace std;

int main(){
    int N;
    cin>>N;

    int min_so_far = INT_MAX;
    int max_so_far = INT_MIN;

    for(int i=0; i<N; i++){
        int num;
        cin>>num;
        if(num<min_so_far) min_so_far = num;
        if(num>max_so_far) max_so_far = num;
    }

    cout<<"Min so far"<<min_so_far<<endl;
    cout<<"Max so far"<<max_so_far<<endl;

    return 0;
}

