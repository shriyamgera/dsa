class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        if(n<3) return false;
        int a = 0;
        int b = 0;
        for(int i=1;i<n-1;i++){
            if(colors[i]=='A'){
                if(colors[i]==colors[i-1] && colors[i]==colors[i+1]){
                    a++;
                }
            }
            else{
                if(colors[i]==colors[i-1] && colors[i]==colors[i+1]){
                    b++;
                }
            }
        }
        return a>b;
    }
};