class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int start=0,end=0;
        int curr_length=0,max_length=0;
        while(end<n){
            if(mp.find(s[end])==mp.end()){
                mp[s[end]]=end;
                curr_length++;
            } else {
                max_length=max(max_length,curr_length);
                int index=mp[s[end]];
                while(start<=index){
                    mp.erase(s[start]);
                    start++;
                }
                mp[s[end]]=end;
                curr_length=end-start+1;
            }
            end++;
        }
        max_length=max(max_length,curr_length);
        return max_length;
    }
};
