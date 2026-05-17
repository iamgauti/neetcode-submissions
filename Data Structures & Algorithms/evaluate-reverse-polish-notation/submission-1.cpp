class Solution {
public:
    bool isSymbol(string str){
        if(str.size()>1)
            return false;
        char a=str[0];
        if(a>='0' && a<='9')
            return false;
        return true;
    }
    int evaluate(int first,int second, string symbol){
        char x=symbol[0];
        switch(x){
            case '+':
                return first+second;
            case '-':
                return first-second;
            case '*':
                return first * second;
            case '/':
                return first/second;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        int n=tokens.size();
        for(int i=0;i<n;i++){
            if(isSymbol(tokens[i])){
                int first=s.top();
                s.pop();
                int second=s.top();
                s.pop();
                s.push(evaluate(second,first,tokens[i]));
            } else {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};
