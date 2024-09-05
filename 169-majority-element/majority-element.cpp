class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el;
        int ct=0;

        for(int i =0; i<nums.size();i++){
            if(ct==0){
                el = nums[i];
                ct++;
                continue;
            }
            if(nums[i] == el){
                ct++;
            }else{
                ct--;
            }
        }

        int count = 0;

        for(int i = 0; i< nums.size(); i++){
            if(nums[i] == el){
                count++;
            }
        }

        if(count>(nums.size()/2)){
            cout<< el;
            return el;
        }else{
            cout<<el;
            return -1;
        } 
    }
};