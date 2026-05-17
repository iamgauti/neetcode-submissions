class Solution {
public:
    bool isPossible(int k,vector<int>& piles, int h){
        int n=piles.size();
        for(int i=0;i<n;i++){
            if(piles[i]%k == 0)
                h-=piles[i]/k;
            else
                h-=(piles[i]/k)+1;
        }

        return h>=0 ? 1 : 0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int mini=1,maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        int ans=maxi;
        while(mini<=maxi){
            int mid=(mini+maxi)/2;
            if(isPossible(mid,piles,h)){
                ans=min(ans,mid);
                maxi=mid-1;
            } else {
                mini=mid+1;
            }
        }
        return ans;
    }
};
