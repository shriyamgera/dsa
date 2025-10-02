class Solution {
public:
    long long solve(long long end, int limit, string s){
        string str = to_string(end);
        int remainingLength = str.size() - s.size();
        if(str.size() < s.size()){
            return 0;
        }
        long long result = 0;
        for(int i=0; i<remainingLength; i++){
            int digit = str[i] - '0';
            if(digit>limit){
                result += pow(limit+1, remainingLength-i );
                return result;
            }else{
                result += digit * pow(limit+1, remainingLength-i-1);
            }
        }
        
        if(str.substr(remainingLength)>=s){
            result += 1;
        }
        return result;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return solve(finish,limit,s) - solve(start - 1,limit,s);
    }
};