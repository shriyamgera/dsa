class Solution {
public:
    int differenceOfSums(int n, int m) {
        int divSum = 0;
        int nonDivSum = 0;

        for(int i=1; i<=n; i++){
            if(i%m==0){
                divSum += i;
            }else{
                nonDivSum += i;
            }
        }

        return nonDivSum-divSum;
    }
};