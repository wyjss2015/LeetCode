//O(N)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp=0;
        vector<int>::size_type i, j;
        for(i=0,j=0;j<prices.size();++j){
            if(prices[j]>prices[i] && mp<prices[j]-prices[i])
                mp = prices[j]-prices[i];
            else if(prices[j]<prices[i])
                i = j;
        }
        return mp;
    }
};
