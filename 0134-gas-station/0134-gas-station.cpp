class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int tank = 0, start = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            
            tank += gas[i] - cost[i];
            
            // If tank is negative, we cannot complete the circuit from `start` to `i`
            if (tank < 0) {
                // Set next station as the new starting point
                start = i + 1;
                // Reset tank as we are considering a new starting point
                tank = 0;
            }
        }
        
        // If total gas is less than total cost, it's impossible to complete the circuit
        return (totalGas >= totalCost) ? start : -1;
    }
};
