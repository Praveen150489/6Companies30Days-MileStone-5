// Number of Provinces.

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool> vis(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                ans++;
                solve(i,adj,vis);
            }
        }
        return ans;
    }
    void solve(int start,vector<int> adj[],vector<bool>& vis){
        vis[start]=true;
        for(auto x:adj[start]){
            if(vis[x]==false){
                solve(x,adj,vis);
            }
        }
    }
};
