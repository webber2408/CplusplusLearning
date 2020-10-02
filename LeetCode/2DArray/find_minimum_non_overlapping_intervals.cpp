#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> v1, vector<int> v2){
    return v1[1] < v2[1];
}

int eraseOverlapIntervals(vector<vector<int>> &intervals){
    sort(intervals.begin(), intervals.end(), compare);
    int i=1, ans = 0, last = 0;
    while(i<intervals.size()){
        if(intervals[i][0] < intervals[last][1])
            ans++;
        else
            last = i;
        i++;
    }
    return ans;
}

int main(){
    int N, j=0;
    cin>>N;
    vector<vector<int>> intervals;
    for(int i=0; i<N; i++){
        vector<int> temp;
        int num;
        for(int j=0; j<2; j++){
            cin>>num;
            temp.push_back(num);
        }
        intervals.push_back(temp);
    }

    // for(int i=0; i<intervals.size(); i++){
    //     for(int j=0; j<intervals[i].size(); j++){
    //         cout<<intervals[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int ans = eraseOverlapIntervals(intervals);

    cout<<ans<<endl;

    return 0;
}