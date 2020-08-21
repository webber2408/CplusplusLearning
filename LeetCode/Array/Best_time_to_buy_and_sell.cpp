#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> & prices){
    int max1 = 0, max2 = 0;
    if(prices.size() <= 1)
        return 0;
    int i=0;
    while(i < prices.size() - 1){
        while((i < prices.size()-1) && (prices[i+1] <= prices[i]))
            i++;
        if(i == prices.size()-1)
            return 0;
        int buy = i++;
        while((i < prices.size()) && (prices[i] >= prices[i-1]))
            i++;
        int sell = i-1;
        int profit = prices[sell] - prices[buy];
        if(profit >= max1){
            max2 = max1;
            max1 = profit;
        }else if(profit > max2){
            max2 = profit;
        }
    }
    return (max1 + max2);
}
int solution(vector<int> & nums){
    int firstBuy = INT_MIN, secondBuy = INT_MIN, firstSold = 0, secondSold = 0;
    for (int i = 0; i < nums.size(); i++) {
        firstBuy = max(firstBuy, -nums[i]);
        firstSold = max(firstSold, firstBuy + nums[i]);
        secondBuy = max(secondBuy, firstSold - nums[i]);
        secondSold = max(secondSold, secondBuy + nums[i]);
    }
    return secondSold;
}

int main(){
    int N;
    cin>>N;
    vector<int> prices;
    int num;
    for(int i=0; i<N; i++){
        cin>>num;
        prices.push_back(num);
    }

    int ans = maxProfit(prices);
    cout<<ans<<endl;

    return 0;
}