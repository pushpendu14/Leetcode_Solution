class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        int sum=0;
        for(string x : operations){
            if(isdigit(x[0]) || x[0]=='-' && x.size()>1){
                st.push(stoi(x));
            }else if(x=="+"){
                int top=st.top();
                st.pop();
                int top2Sum=top+st.top();
                st.push(top);
                st.push(top2Sum);
            }else if(x=="D"){
                int ns= 2*st.top();
                st.push(ns);
            }else{
                st.pop();
            }
        }
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};
