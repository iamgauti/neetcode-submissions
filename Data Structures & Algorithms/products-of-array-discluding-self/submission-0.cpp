class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>prodRight(n+1,1);
        for(int i=n-1;i>=0;i--){
            prodRight[i]=prodRight[i+1]*nums[i];
        }
        int leftProd=1;
        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            ans[i]=leftProd*prodRight[i+1];
            leftProd*=nums[i];
        }
        return ans;
    }
};
