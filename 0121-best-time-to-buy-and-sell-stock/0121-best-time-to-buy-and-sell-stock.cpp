class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        int maxProfit = 0, minValueSoFar = prices[0];
        
        for(int i=0; i < prices.size(); i++){
            
            minValueSoFar = min(minValueSoFar, prices[i]);
            maxProfit= max(maxProfit, prices[i]-minValueSoFar);

        }
        
        return maxProfit;
        
    }
};





//     int maxProfit(vector<int>& prices) {
        
//         int pricesLength = prices.size();
//         int result = 0;
        
//         for(int i=0; i < pricesLength-1; i++){
//             for (int j=i+1; j<pricesLength; j++){
//                 if(result < prices[j]-prices[i]){
//                     result = prices[j]-prices[i];
//                 }
//             }
//         }
        
//         return result;
        
//     }