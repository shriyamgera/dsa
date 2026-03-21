class Solution {
public:
    int reverse(int x) {
        int newX = 0;
        while(x!=0){
            int a = x%10;
            x = x/10;
            if((newX>(INT_MAX/10)) || (newX<(INT_MIN/10))) return 0;
            newX = (newX*10)+a;
        }
        return newX;
    }
};