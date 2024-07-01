class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        bool ans=false;

        for(int i=0;i<arr.size();i++){
            if(arr[i]%2 != 0){
                count++;
                if(count == 3){
                    ans=true;
                }
            }else{
                count = 0;
            }
        }

        return ans;
    }
};