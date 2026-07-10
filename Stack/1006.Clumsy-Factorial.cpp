class Solution {
public:
    int clumsy(int n) {
        stack<int>st;
        st.push(n);
        n--;

        int op=0;
        while(n>0){

            if(op==0){
                int top=st.top();
                st.pop();
                st.push(top*n);
            }else if(op==1){
                int top=st.top();
                st.pop();
                st.push(top/n);
            }else if(op==2){
                st.push(n);
            }else {
                st.push(-n);
            }
            n--;
            op=(op+1)%4;
        }
        int sum=0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};
