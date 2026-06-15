class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";

        for(string s : words){
            int num=0;
            for(char c : s){
                num +=weights[c-'a'];
            }
            num =num%26;
            char temp='z'-num;
            ans +=temp;
        }
        return ans;
    }
};
