class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        vector<pair<int,int>>car(n);
        for(int i=0;i<n;i++){
            car[i]={position[i],speed[i]};
        }
        sort(car.begin(),car.end());
        stack<pair<int,int>>s;
        for(int i=n-1;i>=0;i--){
            if(s.empty())
                s.push(car[i]);
            else {
                pair<int,int>top=s.top();
                double timeTakenByTop= (target-top.first)/(double)top.second;
                double timeTakenByCurrent= (target-car[i].first)/(double)car[i].second;
                if(timeTakenByTop < timeTakenByCurrent)
                    s.push(car[i]);
            }
        }
        return s.size();
    }
};
