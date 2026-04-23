class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";
        int n= strs.size();
        for(int i=0;i<n;i++){
            string a=strs[i];
            //cout<<"a: "<<a<<endl;
            for(int j=0;j<a.size();j++){
                ans+=to_string((int)(unsigned char)a[j])+" ";
            }
            ans+='/';
        }
        //cout<<ans;
        return ans;
    }

    char convertToLetter(string s){
        //int n=s.size();
        int val=stoi(s);
        //cout<<"val"<<val<<" "<<(char)val<<endl;
        return (char)val;
    }

    vector<string> decode(string s) {
        int n=s.size();
        vector<string>ans;
        for(int i=0;i<n;){
            string temp1="";
            while(s[i]!='/'){
                string temp2="";
                while(i < n && s[i]!=' ' && s[i] != '/'){
                    temp2+=s[i];
                    i++;
                }
                //cout<<temp2<<endl;
                temp1+=convertToLetter(temp2);
                i++;
            }
            //cout<<temp1<<endl;
            ans.push_back(temp1);
            i++;
        }
        return ans;
    }
};
