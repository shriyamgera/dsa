class Solution {
public:
    int differenceOfSums(int n, int m) {
        int k = n/m;
        int num2 = (k*(k+1)/2)*m;
        int totalSum = n*(n+1)/2;
        int num1 = totalSum-num2;
        return num1-num2;
    }
};