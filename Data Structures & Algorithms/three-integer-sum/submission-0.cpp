class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int start=i+1,end=n-1;
            while(start<end){
                if((nums[start]+nums[end]+nums[i]) == 0){
                    ans.push_back({nums[i],nums[start],nums[end]});
                    start++;end--;
                    while(start<end && nums[start]==nums[start-1]){
                        start++;
                    }
                    while(start<end && nums[end]==nums[end+1]){
                        end--;
                    }
                }
                else if((nums[start]+nums[end]+nums[i]) < 0){
                    start++;
                    while(start<end && nums[start]==nums[start-1]){
                        start++;
                    }
                } else {
                    end--;
                    while(start<end && nums[end]==nums[end+1]){
                        end--;
                    }
                }
            }
        }
        return ans;
    }
};
