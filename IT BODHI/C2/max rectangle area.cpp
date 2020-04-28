#include<bits/stdc++.h>
#include<stack>
using namespace std;
stack <int> s1;
stack <int> s2;
void maxRectangle(int [],int);
int main(){
    cout<<"Enter histogram size:"<<endl;
    int n;
    cin>>n;
    cout<<"Enter histogram array:"<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    maxRectangle(arr,n);
}
void maxRectangle(int arr[],int n){
    int maxI = -1;
    int startIndex = 0;
    int finalStart = 0;
    int finalEnd = 0;
    for(int i=0;i<n;i++){
        if(i==0){
            s1.push(arr[i]);
            //s2.push(sub[i]);
            s2.push(i);
        }
        else{
            if(arr[i] >= s1.top()){
                s1.push(arr[i]);
                //s2.push(sub[i]);
                s2.push(i);
            }else{
                while(arr[i] < s1.top() && !s1.empty()){
                        cout<<"h"<<endl;
                    int temp = s1.top();
                    int tempIndex = s2.top();
                    int tempArea = temp*(i - tempIndex);
                    startIndex = tempIndex;
                    s1.pop();
                    s2.pop();
                    if(tempArea > maxI){
                        maxI = tempArea;
                        finalStart = tempIndex;
                        finalEnd = i-1;
                    }
                    if(s1.empty()){
                        break;
                    }
                }
                s1.push(arr[i]);
                s2.push(startIndex);
            }
        }

        if(i == n-1 && !s1.empty()){
            while(!s1.empty()){
                    int temp = s1.top();
                    int tempIndex = s2.top();
                    int tempArea = temp*((i+1) - tempIndex);
                    if(tempArea > maxI){
                        maxI = tempArea;
                        finalStart = tempIndex;
                        finalEnd = i-1;
                    }
                    s1.pop();
                    s2.pop();
            }
        }
    }

    cout<<"Max rectangle area is "<<endl;
    cout<<maxI<<endl;
    cout<<"start from "<<finalStart<<" end in "<<finalEnd<<endl;
}
