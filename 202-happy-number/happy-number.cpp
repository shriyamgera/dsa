class Solution {
public:

    int findSum(int n){
        int sum = 0;
        while(n){
            int digit = n%10;
            sum+=digit*digit;
            n=n/10;
        }

        return sum;
    }
    bool isHappy(int n) {
        if(n<=0){
            return false;
        }

        unordered_set<int> cache;
        while(cache.find(n)==cache.end()){
            cache.insert(n);
            n=findSum(n);
            if(n==1){
                return true;
            }
        }

        return false;
    }
};