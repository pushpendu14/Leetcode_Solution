class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>q;

        for(int x : piles){
            q.push(x);
        }

        while(k>0){
            int x = q.top();
            q.pop();
            q.push(x - floor(x/2));
            k--;
        }
        int count=0;
        while(!q.empty()){
            count += q.top();
            q.pop();
        }
        return count;
    }
};
