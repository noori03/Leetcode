class Solution {
public:
    bool findSuccessors(vector<int> & hand, int groupSize, int i,int n){
        int next = hand[i] +1;
        hand[i]=-1;
        int count =1;
        i +=1;
        while(i<n  && count<groupSize){
            if(hand[i]==next){
                next = hand[i] +1;
                hand[i] =-1;
                count++;
            }
            i++;
        }
        return count== groupSize;

    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize !=0 )return 0;
         int n= hand.size();
         sort(hand.begin(),hand.end());
         for(int i=0;i<n;i++){
            if(hand[i] >=0){
                if(!findSuccessors(hand,groupSize,i,n) ) return false;
            }
         }
         return 1;

    }
};