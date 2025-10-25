class Solution {
public:
    int totalMoney(int n) {
        int initial = 1;
        int current = 1;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if ((i-1) % 7 == 0 && i!=1) {
                initial++;
                current = initial;
            }
            ans += current;
            current++;
        }
        return ans;
    }
};