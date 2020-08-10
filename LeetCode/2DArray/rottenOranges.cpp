#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid){
    int minutesPassed = 0;
    bool changed = false;
    while(true){
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 2){
                    //top
                    if(i-1 >= 0 && grid[i-1][j] == 1){
                        grid[i-1][j] = 2;
                        changed = true;
                    }
                    //right
                    if(j+1 < grid[i].size() && grid[i][j+1] == 1){
                        grid[i][j+1] = 2;
                        changed = true;
                    }
                    //bottom
                    if(i+1 < grid.size() && grid[i+1][j] == 1){
                        grid[i+1][j] = 2;
                        changed = true;
                    }
                    //left
                    if(j-1 >= 0 && grid[i][j-1] == 1){
                        grid[i][j-1] = 2;
                        changed = true;
                    }
                }
            }
        }

        if(!changed)
            break;
        minutesPassed++;
        changed = false;
    }
    
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
            if(grid[i][j] == 1)
                return -1;
        }
    }
    
    return minutesPassed;
}

int main(){
    int m, n;
    cin>>m>>n;

    vector<vector<int>> oranges;

    for(int i=0; i<m; i++){
        vector<int> temp;
        int num;
        for(int j=0; j<n; j++){
            cin>>num;
            temp.push_back(num);
        }
        oranges.push_back(temp);
    }

    // for(int i=0; i<oranges.size(); i++){
    //     for(int j=0; j<oranges[i].size(); j++){
    //         cout<<oranges[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int ans = orangesRotting(oranges);

    cout<<ans<<endl;

    return 0;
}