class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<char> st;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='}' || s[i]==']' || s[i]==')'){
                st.push(s[i]);
            }else if(s[i]=='{' || s[i]=='[' || s[i]=='('){

                if(st.empty()) return false;
                char top = st.top();
                if( s[i]=='(' && top !=')' || 
                s[i]=='{' && top != '}' || 
                s[i]=='[' && top !=']'){
                    return false;
                }
                st.pop();
            }
        }
        if(st.empty()){
            return true;

        }
        return false;
    }
};
