class Solution {
public:
    int compress(vector<char>& chars) {
        int l=0;
        int r=0;
        int count=1;
        while(r<=chars.size()-1){
            r++;
            if(r < chars.size() && chars[r] == chars[r-1]) count++;
            else{
                chars[l] = chars[r-1];
                l++;
                if(count>1){
                    string countStr = to_string(count);
                    for(int i=0;i<countStr.size();i++){
                        chars[l] = countStr[i];
                        l++;
                    }
                }
                count = 1;
            }
        }
        return l;
    }
};