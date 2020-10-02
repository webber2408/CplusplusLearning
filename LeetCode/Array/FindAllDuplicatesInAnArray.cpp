#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> findDuplicates(vector<int> &nums){
    unordered_map<int, int> hashMap;
    vector<int> result;

    for(auto &it: nums){
        // cout<<it;
        if(hashMap.find(it) == hashMap.end())
            hashMap.insert(make_pair(it, 1));
        else{
            // cout<<" here"<<endl;
            result.push_back(it);
        }
    }

    return result;
}

int main(){

    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &it: nums) 
        cin>>it;

    vector<int> result = findDuplicates(nums);

    for(auto &it: result) 
        cout<<it<<" ";

    return 0;
}