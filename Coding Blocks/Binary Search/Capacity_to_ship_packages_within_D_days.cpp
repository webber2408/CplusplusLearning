#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repa(i, a, n) for(int i = a; i <= (n); ++i)
#define repd(i, n) for(int i = n; i >= 0; --i)

bool isPossibleToShip(vector<int> weights, int d, int min_capacity){
    int days_shipped = 1;
    int weights_shipped = 0;

    for(int i=0; i<weights.size(); i++){
        if(weights_shipped + weights[i] > min_capacity){
            days_shipped++;
            weights_shipped = weights[i];
            if(days_shipped > d){
                return false;
            }
        }else{
            weights_shipped += weights[i];
        }
    }

    cout<<"d"<<days_shipped<<endl;
    return true;
}

int max_element(vector<int> weights){
    int max_ele = INT_MIN;
    for(int i=0; i<weights.size(); i++){
        if(weights[i] > max_ele){
            max_ele = weights[i];
        }
    }
    return max_ele;
}

int findMinCapacity(vector<int> weights, int d){
    
    int n = weights.size();
    if(n < d){
        return -1;
    }

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += weights[i];
    }

    int l = max_element(weights);
    int r = sum;

    cout<<l<<" "<<r<<endl;

    int ans = INT_MAX;

    while(l <= r){
        int m = l + (r-l)/2;
        cout<<"m"<<m<<endl;
        if(isPossibleToShip(weights, d, m)){
            cout<<m<<endl;
            ans = min(ans, m);
            r = m-1;
        }else{
            l = m+1;
        }
    }

    return ans;
}

int findMinCapacityOptimised(vector<int> weights, int d){
    int n = weights.size();
    if(n < d){
        return -1;
    }

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += weights[i];
    }

    int l = max_element(weights);
    int r = sum, m = 0;

    cout<<l<<" "<<r<<endl;

    while(l<=r){
        m = (l+r)/2;
        cout<<"l"<<l<<"r"<<r<<"m"<<m<<endl;
        int sum = 0, days_shipped = 0;
        
        for(int i=0; i<n; i++){
            sum += weights[i];
            if(sum > m){
                days_shipped++;
                sum = weights[i];
            }
        }

        days_shipped++;
        cout<<"days_shipped"<<" "<<days_shipped<<endl;

        if(days_shipped<=d){
            r = m-1;
        }else{
            l = m+1;
        }
    }

    return l;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> weights;

    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        weights.push_back(num);
    }

    int d;
    cin>>d;

    cout<<findMinCapacityOptimised(weights, d)<<endl;

    return 0;
}