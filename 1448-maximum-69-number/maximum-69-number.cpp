class Solution {
public:
    int maximum69Number (int num) {
        int n = num;
        int latestSix = -1;
        int curr=0;
        while(n>0){
            int d = n%10;
            if(d==6){
                latestSix = curr;
            }
            n /=10;
            curr++;
        }
        if (latestSix == -1) return num;
        return num + 3*(pow(10,latestSix));
    }
};