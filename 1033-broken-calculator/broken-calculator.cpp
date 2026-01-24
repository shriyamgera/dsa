class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(target<startValue) return startValue-target;
        if(target==startValue) return 0;

        int ans = 0;
        while(startValue<target){
            if(target%2==0) target /=2;
            else target +=1;
            ans++;
        }
        return ans+startValue-target;
    }
};
