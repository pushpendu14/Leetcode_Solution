class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long>q;
        for(int x : gifts){
            q.push(x);
        }
        while(k>0){
            long long x = q.top();
            q.pop();
            q.push((long long)(sqrt(x)));
            k--;
        }
        long long count=0;
        while(!q.empty()){
            count += q.top();
            q.pop();
        }
        return count;
    }
};
