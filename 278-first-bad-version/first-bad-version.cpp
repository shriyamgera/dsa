// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1;
        int possibleAns = -1;
        while(s<=n){
            int m = s+(n-s)/2;
            if(isBadVersion(m)){
                possibleAns = m;
                n = m-1;
            }else{
                s = m+1;
            }
        }
        return possibleAns;
    }
};