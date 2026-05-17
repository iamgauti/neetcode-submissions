class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>rightMax(n+1,0);
        //rightMax[n-1]=height[n-1];
        for(int i=n-1;i>=0;i--){
            rightMax[i]=max(height[i],rightMax[i+1]);
        }
        int leftMax=0,ans=0;
        for(int i=0;i<n;i++){
            int maxi= min(leftMax,rightMax[i+1]);
            ans+= maxi>height[i] ? maxi-height[i] : 0;
            leftMax=max(leftMax,height[i]);
        }
        return ans;
    }
};
