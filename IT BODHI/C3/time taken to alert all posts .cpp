#include<bits/stdc++.h>
using namespace std;
void calcTime(int [] , int );
int main(){
    cout<<"Enter array size:"<<endl;
    int n;
    cin>>n;
    cout<<"Enter array:"<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    calcTime(arr,n);

    return 0;
}
void calcTime(int arr[],int n){
    int i=0,countX = 0;
    while(arr[i] == 0){
        countX++;
        i++;
    }
    while(arr[i] == 1){

        i++;
    }
    cout<<"Count x = "<<countX<<endl;
    int j = n-1,countY = 0;
    while(arr[j] == 0){
        countY++;
        j--;
    }
    while(arr[j] == 1){

        j--;
    }
    cout<<"Count y = "<<countY<<endl;
    int countMid = 0;
    int maxMidcount = -1;
    cout<<i<<"->"<<j<<endl;
    while(i<=j){
        cout<<"CountMid :"<<countMid<<endl;
        if(arr[i]==0){
            if(countMid >= maxMidcount){
                countMid++;
                maxMidcount = countMid;
            }else{
                countMid++;
            }
            i++;
        }else{
            countMid=0;
            i++;
        }
    }
    cout<<"Final mid count ="<<maxMidcount<<endl;
    int finalMidcount = maxMidcount/2;
    int answer = (countX >= countY && countX >= finalMidcount)?countX:(countY>finalMidcount)?countY:finalMidcount;
    cout<<"Total time taken will be "<<answer<<" units ."<<endl;

}
