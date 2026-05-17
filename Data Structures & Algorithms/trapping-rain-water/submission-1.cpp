class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        // vector<int>rightMax(n+1,0);
        // //rightMax[n-1]=height[n-1];
        // for(int i=n-1;i>=0;i--){
        //     rightMax[i]=max(height[i],rightMax[i+1]);
        // }
        // int leftMax=0,ans=0;
        // for(int i=0;i<n;i++){
        //     int maxi= min(leftMax,rightMax[i+1]);
        //     ans+= maxi>height[i] ? maxi-height[i] : 0;
        //     leftMax=max(leftMax,height[i]);
        // }
        // return ans;
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
                // leftmax=max(leftmax,height[l]);
                // rightmax=max(rightmax,height[r]);
                r--;
            }
            //cout<<l<<" "<<r<<" "<<leftmax<<" "<<rightmax<<" "<<ans<<endl;
        }
        return ans;
    }
};
