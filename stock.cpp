#include <iostream>
#include <vector>
#include <array>

using namespace std;

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int buy, sell, ret = 0;

//         for(int i = 0; i < n-1; i++){
//             buy = prices[i];
//             sell = prices[i+1];
//             for(int j = i+1; j<n; j++){
//                 if(prices[j]>sell){
//                     sell = prices[j];
//                 }
//             }
//             int now = sell - buy;
//             if(ret < now) ret = now;
//         }
//         return ret;
//     }
// };

class Solution{
public:
    int maxProfit(vector<int>& prices){
        
        int n = prices.size();
        vector<int> x(n);
        x[0] = prices[0];
        int max_profit = 0;
        int this_profit;
        for(int i = 1; i<n; i++){
            x[i] = min(x[i-1],prices[i]);
        }

        // 
        for(int i = 0; i<n; i++){
            this_profit = prices[i] - x[i];
            if(this_profit>max_profit) max_profit = this_profit;
        }

        return max_profit;
    }
};

int main(){
    Solution s1;
    vector<int> x {1,5,3,6,4};
    int ret = s1.maxProfit(x);
    cout<<ret<<endl;
}