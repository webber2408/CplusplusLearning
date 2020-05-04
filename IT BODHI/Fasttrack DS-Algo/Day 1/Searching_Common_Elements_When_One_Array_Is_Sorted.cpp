/*
1) Brute Force - O(n2)
2) When one array is sorted - 2.1) Binary Search O(N1logN2)
2) Extra Space - Use Hash - Hash Elements of Smaller Array - O(N1) {Hashing} + O(N2){Searching} ~ O(N)
3) Sort Both arrays - Use two pointers - O(N1+N2) ~ O(N)
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> searchCommonElement(int arr1[], int arr2[], int N1, int N2){
    //Hashing Smaller Array
    unordered_map<int, int> hashMap;
    vector<int> commonElements;
    if(N1<N2){
        //Populating hash map
        for(int i=0;i<N1;i++){
            if(hashMap.find(arr1[i]) == hashMap.end()){
                hashMap.insert({arr1[i], 1});
            }
        }
        // Hash Map Traversal
        // for(auto & it : hashMap){
        //     cout<<it.first<<endl;    
        // }   
        for(int i=0;i<N2;i++){
            if(hashMap.find(arr2[i]) != hashMap.end()){
                commonElements.push_back(arr2[i]);
                hashMap.erase(arr2[i]);
            }
        }
    }else{
        // Populating hash map
        for(int i=0;i<N2;i++){
            if(hashMap.find(arr2[i]) == hashMap.end()){
                hashMap[arr2[i]] = 1;
            }
        }
        for(int i=0;i<N1;i++){
            if(hashMap.find(arr1[i]) != hashMap.end()){
                commonElements.push_back(arr1[i]);
                hashMap.erase(arr1[i]);
            }
        }
    }

    return commonElements;
}
int main(){
    int N1, N2;
    cout<<"Enter array 1 size:"<<endl;
    cin>>N1;
    int arr1[N1];
    cout<<"Enter array 1 elements:"<<endl;
    for(int i=0;i<N1;i++){
        cin>>arr1[i];
    }
    cout<<"Enter array 2 size:"<<endl;
    cin>>N2;
    int arr2[N2];
    cout<<"Enter sorted array 2 elements:"<<endl;
    for(int i=0;i<N2;i++){
        cin>>arr2[i];
    }

    vector<int> commonElements = searchCommonElement(arr1, arr2, N1, N2);
    cout<<"Common Elements"<<endl;

    for(int i=0;i<commonElements.size();i++){
        cout<<commonElements[i]<<" ";
    }

    return 0;
}