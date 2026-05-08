/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int>count(1000001,0);
        int n=intervals.size();
        for(int i=0;i<n;i++){
            count[intervals[i].start]++;
            count[intervals[i].end]--;
        }
        int ans=count[0];
        for(int i=1;i<1000001;i++){
            count[i]=count[i-1]+count[i];
            ans=max(ans,count[i]);
        }
        return ans;
    }
};
