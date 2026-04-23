class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==0)
            return 0;
        vector<int>maxVal(n,1);
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]==nums[i]+1){
                    maxVal[j]=max(maxVal[j],maxVal[i]+1);
                    ans=max(ans,maxVal[j]);
                }
            }
        }
        return ans;
    }
};
