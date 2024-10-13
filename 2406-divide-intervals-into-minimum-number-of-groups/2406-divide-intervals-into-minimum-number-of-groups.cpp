class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        // way to define min heap
        priority_queue<int , vector<int> , greater<int>> pq;
        for(auto it: intervals){
            int st = it[0];
            int end = it[1];
            if(!pq.empty()  && st > pq.top()){
                  pq.pop();
            }
            pq.push(end);
        }
        return pq.size();
    }
};