class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1,leftmax=height[0],rightmax=height[n-1],ans=0;
        while(l<=r){
            leftmax=max(leftmax,height[l]);
            rightmax=max(rightmax,height[r]);
            if(height[l]<=height[r]){
                int maxi=min(leftmax,rightmax);
                ans+= maxi>height[l] ? maxi-height[l] : 0;
                l++;
            }
            else {
                int maxi=min(leftmax,rightmax);
                ans+= maxi>height[r] ? maxi-height[r] : 0;
                r--;
            }
        }
        return ans;
    }
};
