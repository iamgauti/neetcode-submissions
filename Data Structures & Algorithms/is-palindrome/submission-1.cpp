class Solution {
public:
    bool isAlphaNumeric(char a){
        if((a>='0' && a<='9') || (a>='a' && a<='z') || (a>='A' && a<='Z'))
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        int start=0,end=s.size()-1;
        while(start<=end){
            while(start<=end && !isAlphaNumeric(s[start]))
                start++;
            while(start<=end && !isAlphaNumeric(s[end]))
                end--;
            //cout<<start<<" "<<end<<endl;
            if(start<=end && tolower(s[start])!=tolower(s[end]))
                return false;
            start++;end--;
        }
        return true;
    }
};
