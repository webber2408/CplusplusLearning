/*
1) Brute Force - 2 Loops O(n2)
2) Using an array and a hash O(n2) - Implemented
3) Using a doubly linked list and a hash o(n) - Not Implemented
*/
#include<bits/stdc++.h>
using namespace std;

int getFirstNonRepeatedNumberN2(int arr[], int N){
    vector<int> nonRepeatedItems;

    unordered_map<int, int> repeatedHashMap;
    for(int i=0;i<N;i++){
        if(repeatedHashMap.find(arr[i]) == repeatedHashMap.end()){
            nonRepeatedItems.push_back(arr[i]);
            repeatedHashMap[arr[i]] = 1;
        }else{
            for(vector<int>::iterator it=nonRepeatedItems.begin();it < nonRepeatedItems.end();it++){
                if(*it == arr[i])
                    nonRepeatedItems.erase(it);
            }
        }
    }
    if(nonRepeatedItems.size() == 0)
        return -1;
    return nonRepeatedItems[0];
}
int main(){
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    int ans = getFirstNonRepeatedNumberN2(arr, N);
    cout<<ans<<endl;
    return 0;
}