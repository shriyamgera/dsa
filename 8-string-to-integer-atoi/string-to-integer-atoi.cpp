class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        long long ans = 0;
        int sign = 1;

        while(i<n && (s[i] == ' '))i++;

        if(i<n && (s[i] == '-' || s[i] == '+')){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while(i<n && isdigit(s[i])){
            if (ans > (INT_MAX - (s[i] - '0')) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            ans = ans * 10 + (s[i] - '0');
            i++;
        }

        return ans * sign;
    }
};