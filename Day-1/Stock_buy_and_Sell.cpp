int maxProfit(vector<int>& prices) {
        int mn = prices[0], profit=0 ;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]>mn){
                profit = max(profit, prices[i]-mn);
            }else{
                mn = prices[i];
            }
        }
        return profit;
    }