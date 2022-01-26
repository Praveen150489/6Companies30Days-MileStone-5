// Number of Boomerangs.

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        vector<long long> g[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=i){
                    long long x=abs(points[j][0]-points[i][0])*abs(points[j][0]-points[i][0]) + abs(points[j][1]-points[i][1])*abs(points[j][1]-points[i][1]);
                    g[i].push_back(x);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            map<long long,int> mp;
            for(int j=0;j<g[i].size();j++){
                mp[g[i][j]]++;
            }
            for(auto x:mp){
                if(x.second>=2){
                    ans+=(x.second)*(x.second-1);
                }
            }
        }
        return ans;
    }
};
