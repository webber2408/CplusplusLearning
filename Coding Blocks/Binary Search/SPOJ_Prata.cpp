/*
IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. 
The subcommittee members are asked to go to food connection and get P(P<=1000) pratas packed for the function. 
The stall has L cooks(L<=50) and each cook has a rank R(1<=R<=8).
A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 
1 more prata in 3R minutes and so on(he can only cook a complete prata) ( For example if a cook is ranked 2.. 
he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes 
hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata). 
The webmaster wants to know the minimum time to get the order done. Please write a program to help him out.

 

Input
The first line tells the number of test cases. Each test case consist of 2 lines. 
In the first line of the test case we have P the number of prata ordered. 
In the next line the first integer denotes the number of cooks L and L integers follow in the same line each denoting the rank of a cook.

Output
Print an integer which tells the number of minutes needed to get the order done.
*/
#include<bits/stdc++.h>
using namespace std;

bool isPossibleToMakePratas(int cooks[], int l, int p, int min_time){
    int totalPratas = 0, time_taken = 0;
    for(int i=0; i<l; i++){
        int temp = 1;
        while(temp <= p){
            if(cooks[i]*temp + time_taken > min_time){
                time_taken = 0;
                break;
            }else{
                time_taken += cooks[i]*temp;
                temp++;
                totalPratas++;
            }
        }
    }
    if(totalPratas < p){
        return false;
    }
    return true;
}

int getMinimumTime(int cooks[], int l, int p){
    int minRank = INT_MAX;
    for(int i=0; i<l; i++){
        if(cooks[i] < minRank)
            minRank = cooks[i];
    }

    int temp = 1, minTime = 0;
    while(temp <= p){
        minTime += minRank*temp;
        temp++;
    }
    
    int s = 0;
    //e will be time taken by the fastest cook himself to cook the entire pratas.
    int e = minTime;
    int ans = INT_MAX;

    while(s<=e){
        int m = s + (e-s)/2;
        // cout<<"s"<<s<<"e"<<e<<"m"<<m<<endl;
        if(isPossibleToMakePratas(cooks, l, p, m)){
            // cout<<m<<endl;
            ans = min(ans, m);
            e = m-1;
        }else{
            s = m+1;
        }
    }

    return ans;
}

int main(){

    int t;
    cin>>t;

    for(int i=0; i<t; i++){
        int p, l;
        cin>>p>>l;
        int cooks[l];
        for(int i=0; i<l; i++){
            cin>>cooks[i];
        }
        cout<<getMinimumTime(cooks, l, p)<<endl;
    }

    return 0;
}