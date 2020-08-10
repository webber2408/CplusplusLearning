#include<bits/stdc++.h>
using namespace std;

struct ele{
    int time;
    int x, y;
};

int getMinutesPassed(vector<vector<int>> &grid){
    queue<ele> rottenOranges;
    int minutes = 0, n;

    //Push all rotten oranges into queue
    for(int i=0; i<grid.size(); i++){
        n = grid[i].size();
        for(int j=0; j<grid[i].size(); j++){
            if(grid[i][j] == 2){
                ele re;
                re.time = 0;
                re.x = i;
                re.y = j;
                rottenOranges.push(re);
            }
        }
    }

    while(!rottenOranges.empty()){
        ele e1 = rottenOranges.front();
        ele temp = e1;
        
        //top
        if(e1.x-1 >= 0 && grid[e1.x-1][e1.y] == 1){
            grid[e1.x-1][e1.y] = 2;
            temp.time = e1.time+1;
            temp.x = e1.x-1;
            temp.y = e1.y;
            rottenOranges.push(temp);
        }

        //right
        if(e1.y+1 < n && grid[e1.x][e1.y+1] == 1){
            grid[e1.x][e1.y+1] = 2;
            temp.time = e1.time+1;
            temp.x = e1.x;
            temp.y = e1.y+1;
            rottenOranges.push(temp);
        }

        //bottom
        if(e1.x+1 < grid.size() && grid[e1.x+1][e1.y] == 1){
            grid[e1.x+1][e1.y] = 2;
            temp.time = e1.time+1;
            temp.x = e1.x+1;
            temp.y = e1.y;
            rottenOranges.push(temp);
        }

        //left
        if(e1.y-1 >= 0 && grid[e1.x][e1.y-1] == 1){
            grid[e1.x][e1.y-1] = 2;
            temp.time = e1.time+1;
            temp.x = e1.x;
            temp.y = e1.y-1;
            rottenOranges.push(temp);
        }

        minutes = temp.time;
        rottenOranges.pop();
    }

    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
            if(grid[i][j] == 1)
                return -1;
        }
    }

    return minutes;
}

int main(){
    int m, n;
    cin>>m>>n;
    vector<vector<int>> grid;
    for(int i=0; i<m; i++){
        vector<int>temp;
        int num;
        for(int j=0; j<n; j++){
            cin>>num;
            temp.push_back(num);
        }
        grid.push_back(temp);
    }

    int answer = getMinutesPassed(grid);

    cout<<answer<<endl;

    return 0;
}