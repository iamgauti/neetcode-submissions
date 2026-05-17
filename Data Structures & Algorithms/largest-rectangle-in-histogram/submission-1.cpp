class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>s;
        int ans=0;
        for(int i=0;i<n;i++){
            if(!s.empty()){
                //cout<<s.top()<<" "<<i<<endl;
                while(!s.empty() && heights[s.top()]>=heights[i]){
                    int curr=i;
                    int last = s.top();
                    s.pop();
                    int first = !s.empty() ? s.top() : -1;
                    ans=max(ans,heights[last]*(curr-first-1));
                    //cout<<ans<<" "<<last<<" "<<curr<<" "<<first<<endl;
                }
            }
            s.push(i);
        }
        while(!s.empty()){
            int curr=n;
            int last = s.top();
            s.pop();
            int first = !s.empty() ? s.top() : -1;
            ans=max(ans,heights[last]*(curr-first-1));
        }
        return ans;
    }
};
