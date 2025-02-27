class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int leftPointer = 0;
        int rightPointer = 1;
        int runningMax = 0;
        while(rightPointer < prices.size())
        {
            if(prices[rightPointer] - prices[leftPointer] > 0)
            {
                runningMax = max(runningMax, prices[rightPointer] - prices[leftPointer]);
            }
            else
            {
                leftPointer = rightPointer;
            }
            rightPointer++;
        }    
        return runningMax;  
    }
};