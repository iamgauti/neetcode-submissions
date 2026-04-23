class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0],maxi=prices[0],ans=0;
        for(int i=1;i<n;i++){
            if(prices[i]<mini){
                ans=max(ans,maxi-mini);
                mini=prices[i];
                maxi=prices[i];
            } else {
                maxi=max(maxi,prices[i]);
            }
        }
        return max(ans,maxi-mini);
    }
};
