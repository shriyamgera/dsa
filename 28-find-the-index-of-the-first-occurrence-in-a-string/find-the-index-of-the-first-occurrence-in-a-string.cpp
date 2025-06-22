class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int m = haystack.size();
        for(int i = 0;i<haystack.length();i++){
            if(haystack[i] == needle[0]){
                if(n+i>m){
                    return -1;
                }
                if(haystack.substr(i,n) == needle){
                    return i;
                }
            }
        }
        return -1;
    }
};