class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>prefix(n+1);
        prefix[0]=0;
        for(int i=1; i<=n; i++){
            prefix[i]=gain[i-1]+prefix[i-1];
        }
        int maxGain=INT_MIN;

        for(int i=0; i<prefix.size(); i++){
            if(prefix[i] > maxGain){
                maxGain=prefix[i];
            }
        }
        return maxGain;
    }
};
