class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count=numBottles;
        int rem=0,temp=0;
        while(numBottles>=numExchange){
            temp=numBottles/numExchange;
            rem=numBottles%numExchange;
            count+=temp;
            numBottles= temp+rem;
        }
        return count;
    }
};