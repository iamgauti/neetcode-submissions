class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";

        vector<int> freq(128, 0);

        for(char c : t)
            freq[c]++;

        int required = t.size();

        int l = 0;
        int minLen = INT_MAX;
        int start = 0;

        for(int r = 0; r < s.size(); r++)
        {
            // expand window
            if(freq[s[r]] > 0)
                required--;

            freq[s[r]]--;

            // shrink window when valid
            while(required == 0)
            {
                if(r - l + 1 < minLen)
                {
                    minLen = r - l + 1;
                    start = l;
                }

                // remove left char
                freq[s[l]]++;

                if(freq[s[l]] > 0)
                    required++;

                l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
