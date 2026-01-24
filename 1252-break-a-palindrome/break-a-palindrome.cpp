class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n==1) return "";
        bool found = false;
        for(int i=0; i<n/2; i++){
            if(palindrome[i] != 'a') {
                palindrome[i] = 'a';
                found = true;
                break;
            }
        }
        if(!found) palindrome[n-1] = 'b';
        return palindrome;
    }
};