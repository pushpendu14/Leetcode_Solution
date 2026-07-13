// 1st Approach Using 2 Stacks
class Solution {
public:
    bool checkValidString(string s) {
        stack<int>openSt;
        stack<int>starSt;

        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                openSt.push(i);
            }else if(s[i]=='*'){
                starSt.push(i);
            }else {
                if(!openSt.empty()){
                    openSt.pop();
                }else if(!starSt.empty()){
                    starSt.pop();
                }else{
                    return false;
                }
                
            }
        }
        while(!openSt.empty() && !starSt.empty()){
            if(starSt.top() > openSt.top()){
                openSt.pop();
                starSt.pop();
            }else{
                return false;
            }
        }
        return openSt.empty();
    }
};


// Second Approach using GREEDY APPROACH

class Solution {
public:
    bool checkValidString(string s) {
        int minOpen=0;
        int maxOpen=0;

        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                minOpen++;
                maxOpen++;
            }else if(s[i]==')'){
                minOpen--;
                maxOpen--;
            }else{
                minOpen--;
                maxOpen++;
            }
            minOpen=max(0,minOpen);
            if(maxOpen<0) return false;

        }
        return minOpen==0;
    }
};
