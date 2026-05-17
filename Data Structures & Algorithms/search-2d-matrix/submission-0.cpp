class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int m=nums.size(),n=nums[0].size();
        int l=0,h=m-1;
        int row=0;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid][0]==target)
                return true;
            if(nums[mid][0]<target){
                row=mid;
                l=mid+1;
            }
            else
                h=mid-1;
        }
        l=0;h=n-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[row][mid]==target)
                return true;
            if(nums[row][mid]<target){
                l=mid+1;
            }
            else
                h=mid-1;
        }
        return false;
    }
};
