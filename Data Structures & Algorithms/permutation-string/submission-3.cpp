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

        int matches = 0;
        for(int i=0;i<26;i++){
            if(a[i] == b[i]) matches++;
        }

        for(int i=0;i<s2Size-s1Size;i++){
            if(matches == 26){
                return true;
            }

            int out = s2[i] - 'a';
            int in = s2[i + s1Size] - 'a';

            if(a[out] == b[out]) matches--;
            b[out]--;
            if(a[out] == b[out]) matches++;

            if(a[in] == b[in]) matches--;
            b[in]++;
            if(a[in] == b[in]) matches++;
        }

        return matches == 26;
    }
};
