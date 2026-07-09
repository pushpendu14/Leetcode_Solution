class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<char>st;
        int count=0;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]==')'){
                st.push(s[i]);
            }else if(s[i]=='('){
                if(!st.empty()) st.pop();
                else count++;;
            }
        }
        while(!st.empty()){
            count++;
            st.pop();
        }
        return count;
    }
};
