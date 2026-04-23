class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==0)
            return 0;
        int ans=1;
        for(int i=1;i<n;){
            int curr_count=1;
            while(i<n){
                if(nums[i]==nums[i-1]+1){
                    curr_count++;
                    i++;
                } else if(nums[i]==nums[i-1]){
                    i++;
                } else {
                    break;
                }
            }
            ans=max(ans,curr_count);
            i++;
        }
        return ans;
    }
};
