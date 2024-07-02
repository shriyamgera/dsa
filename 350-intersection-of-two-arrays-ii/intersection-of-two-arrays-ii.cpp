class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int> hashMap;
        int s1= nums1.size();
        int s2= nums2.size();

        for(int i=0;i<s1;i++){
            hashMap[nums1[i]]++;;
        }

        for(int i=0;i<s2;i++){
            if(hashMap[nums2[i]]>0){
                hashMap[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }

        
        return ans;
    }
};