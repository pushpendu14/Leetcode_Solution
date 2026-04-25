class Solution {
public:
    bool reorderedPowerOf2(int n) {

        if(n<=0) return  false;

        string num=to_string(n);
        sort(num.begin(),num.end());

        for(int i=0; i<32; i++){
            string power = to_string(1<<i);
            sort(power.begin(),power.end());
            if(num==power) return true;
        }
        return false;
    }
};
