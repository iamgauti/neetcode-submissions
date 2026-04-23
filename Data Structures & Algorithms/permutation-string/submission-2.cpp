class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Size=s1.size(),s2Size=s2.size();
        if(s2Size<s1Size)
            return false;
        vector<int>a(26,0),b(26,0);
        for(int i=0;i<s1Size;i++)
            a[s1[i]-'a']++;
        for(int i=0;i<s1Size;i++)
            b[s2[i]-'a']++;
        for(int i=0;i<s2Size-s1Size;i++){
            if(a==b){
                return true;
            }
            b[s2[i]-'a']--;
            b[s2[i+s1Size]-'a']++;
        }
        return a==b;
    }
};
