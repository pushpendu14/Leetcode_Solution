class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans;
        
            int md= 6*minutes;
            double hd= 30*hour + 0.5 * minutes;
            ans = abs(md-hd);
        
        return min(ans,360.0-ans);
    }
};
