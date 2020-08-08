/*
You have n gifts and you want to give all of them to children. Of course, you don't want to offend anyone, so all gifts should be equal between each other. The i-th gift consists of ai candies and bi oranges.

During one move, you can choose some gift 1≤i≤n and do one of the following operations:

eat exactly one candy from this gift (decrease ai by one);
eat exactly one orange from this gift (decrease bi by one);
eat exactly one candy and exactly one orange from this gift (decrease both ai and bi by one).
Of course, you can not eat a candy or orange if it's not present in the gift (so neither ai nor bi can become less than zero).

As said above, all gifts should be equal. This means that after some sequence of moves the following two conditions should be satisfied: a1=a2=⋯=an and b1=b2=⋯=bn (and ai equals bi is not necessary).

Your task is to find the minimum number of moves required to equalize all the given gifts.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤1000) — the number of test cases. Then t test cases follow.

The first line of the test case contains one integer n (1≤n≤50) — the number of gifts. The second line of the test case contains n integers a1,a2,…,an (1≤ai≤109), where ai is the number of candies in the i-th gift. The third line of the test case contains n integers b1,b2,…,bn (1≤bi≤109), where bi is the number of oranges in the i-th gift.

Output
For each test case, print one integer: the minimum number of moves required to equalize all the given gifts.

Example
input
5
3
3 5 6
3 2 3
5
1 2 3 4 5
5 4 3 2 1
3
1 1 1
2 2 2
6
1 1000000000 1000000000 1000000000 1000000000 1000000000
1 1 1 1 1 1
3
10 12 8
7 5 4
output
6
16
0
4999999995
7
Note
In the first test case of the example, we can perform the following sequence of moves:

choose the first gift and eat one orange from it, so a=[3,5,6] and b=[2,2,3];
choose the second gift and eat one candy from it, so a=[3,4,6] and b=[2,2,3];
choose the second gift and eat one candy from it, so a=[3,3,6] and b=[2,2,3];
choose the third gift and eat one candy and one orange from it, so a=[3,3,5] and b=[2,2,2];
choose the third gift and eat one candy from it, so a=[3,3,4] and b=[2,2,2];
choose the third gift and eat one candy from it, so a=[3,3,3] and b=[2,2,2].
*/
#include<bits/stdc++.h>
using namespace std;

void solution(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int> a(n), b(n);
        for(auto &it: a) cin>>it;
        for(auto &it: b) cin>>it;
        int minA = *min_element(a.begin(), a.end());
        int minB = *min_element(b.begin(), b.end());
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += max(a[i]-minA, b[i]-minB);
        }
        cout<<ans<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t;
    cin>>t;

    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        int a[n], b[n];
        long long int ans = 0;

        int minA = INT_MAX, maxA = INT_MIN;
        for(int j=0; j<n; j++){
            cin>>a[j];
            if(a[j] < minA)
                minA = a[j];
            if(a[j] > maxA)
                maxA = a[j];
        }
        int minB = INT_MAX, maxB = INT_MIN;
        for(int j=0; j<n; j++){
            cin>>b[j];
            if(b[j] < minB)
                minB= b[j];
            if(b[j] > maxB)
                maxB = b[j];
        }

        for(int p=0; p<n; p++){
            if(a[p] > minA && b[p] > minB){
                // cout<<"p"<<p<<endl;
                int t1 = a[p] - minA;
                int t2 = b[p] - minB;
                int minT = min(t1, t2);
                ans += minT;
                a[p] -= minT;
                b[p] -= minT;
            }
        }

        // cout<<"a"<<ans<<endl;

        for(int j=0; j<n; j++){
            ans += 1LL*((a[j]-minA) + (b[j]-minB));
            // cout<<"a"<<ans<<endl;
        }

        cout<<ans<<endl;
    }

    return 0;
}