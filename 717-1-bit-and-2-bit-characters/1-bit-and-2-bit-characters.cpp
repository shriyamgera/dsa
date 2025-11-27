class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int oneCount = 0;
        for(int i=bits.size()-2; i>=0; i--){
            if(bits[i]==0) break;
            oneCount++;
        }
        if(oneCount%2==0) return true;
        else return false;
    }
};