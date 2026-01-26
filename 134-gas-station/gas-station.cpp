class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int gasTotal = 0;
        int costTotal = 0;
        for(int i=0; i<n; i++){
            gasTotal+=gas[i];
            costTotal+=cost[i];
        }

        if(gasTotal<costTotal) return -1;
        int result = 0;
        int currCost = 0;

        for(int i=0; i<n; i++){
            currCost = currCost + gas[i] - cost[i];
            if(currCost<0){
                result = i+1;
                currCost = 0;
            }
            
            
            
        }
        return result;
    }
};