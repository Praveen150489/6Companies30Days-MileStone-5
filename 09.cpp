//  Pacific Atlantic Water Flow.

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set<pair<int,int>> s;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool flag1=false;
                bool flag2=false;
                solve(i,j,heights,vis,s,n,m,flag1,flag2);
                if(flag1==true && flag2==true){
                    s.insert({i,j});
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
    void solve(int x,int y,vector<vector<int>>& heights,vector<vector<bool>>& vis,set<pair<int,int>>& s,int n,int m,bool& flag1,bool& flag2){
        if(s.find({x,y})!=s.end()){
            flag1=true;
            flag2=true;
            return;
        }
        if(x==0 || y==0){
            flag1=true;
        }
        if(x==n-1 || y==m-1){
            flag2=true;
        }
        if(flag1==true && flag2==true){
            return;
        }
        vis[x][y]=true;
        if(x-1>=0 && heights[x-1][y]<=heights[x][y] && vis[x-1][y]==false){
            solve(x-1,y,heights,vis,s,n,m,flag1,flag2);
        }
        if(x+1<n && heights[x+1][y]<=heights[x][y] && vis[x+1][y]==false){
            solve(x+1,y,heights,vis,s,n,m,flag1,flag2);
        }
        if(y-1>=0 && heights[x][y-1]<=heights[x][y] && vis[x][y-1]==false){
            solve(x,y-1,heights,vis,s,n,m,flag1,flag2);
        }
        if(y+1<m && heights[x][y+1]<=heights[x][y] && vis[x][y+1]==false){
            solve(x,y+1,heights,vis,s,n,m,flag1,flag2);
        }
        vis[x][y]=false;
    }
};
