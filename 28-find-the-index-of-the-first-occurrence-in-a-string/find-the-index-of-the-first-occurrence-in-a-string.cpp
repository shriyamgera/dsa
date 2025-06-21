class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack == needle) return 0;

        int ans = 0; // potential starting index
        int j = 0;   // index for needle

        for (int i = 0; i < haystack.length(); i++) {
            if (haystack[i] == needle[j]) {
                j++;
                if (j == needle.length()) return i - j + 1; // match found
            } else {
                i = i - j; // rollback to next starting point
                j = 0;
            }
        }

        return -1;
    }
};
