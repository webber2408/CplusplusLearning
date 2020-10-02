/*
i/p NNNSSEEWE
o/p EEN
*/
#include<iostream>
using namespace std;

int getFinalDisplacement(char ch);
int x = 0;
int y = 0;
int sum = 0;
int main(){
    char ch;
    do{
        ch = cin.get();
        // cout<<ch;
        sum = getFinalDisplacement(ch);
    }while(ch != '\n');

    string shortestString;

    if(x>0){
        while(x>0){
            shortestString += "E";
            x--;
        }
    }else if(x<0){
        while(x<0){
            shortestString += "W";
            x++;
        }
    }
    
    if(y>0){
        while(y>0){
            shortestString += "N";
            y--;
        }
    }else if(y<0){
        while(y<0){
            shortestString += "S";
            y++;
        }
    }

    cout<<"Shortest path is "<<shortestString<<endl;

}

int getFinalDisplacement(char ch){
    switch(ch){
        case 'N': y += 1; break;
        case 'S': y -= 1; break;
        case 'E': x += 1; break;
        case 'W': x -= 1; break;
    }
    return x+y;
}