// Course Schedule-II.

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> g[n];
        int m=prerequisites.size();
        for(int i=0;i<m;i++){
            g[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> vis(n,false);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(g[i].size()==0){
                vis[i]=true;
                ans.push_back(i);
            }
        }
        set<int> s;
        bool flag=true;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                s.insert(i);
                solve(i,g,vis,s,ans,flag);
                if(flag==false){
                    vector<int> v;
                    return v;
                }
            }
        }
        return ans;
    }
    void solve(int start,vector<int> g[],vector<bool>& vis,set<int>& s,vector<int>& ans,bool& flag){
        for(auto x:g[start]){
            if(s.find(x)!=s.end()){
                flag=false;
                return;
            }
            if(x==start){
                flag=false;
                return;
            }
            else if(vis[x]==false){
                s.insert(x);
                solve(x,g,vis,s,ans,flag);
            }
        }
        vis[start]=true;
        s.erase(start);
        ans.push_back(start);
    }
};
