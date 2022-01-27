// ASfar from land as possible.

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        bool slag=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==n-1 || j==n-1){
                    if(grid[i][j]==0){
                        slag=false;
                        break;
                    }
                }
                else{
                    if(grid[i][j]==1){
                        slag=false;
                        break;
                    }
                }
            }
        }
        if(slag==true){
            if(n%2==0){
                return (n/2 -1);
            }
            else{
                return (n/2);
            }
        }
        int ans=INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    queue<pair<int,int>> q;
                    set<pair<int,int>> s;
                    q.push({i,j});
                    s.insert({i,j});
                    int count=q.size();
                    int steps=0;
                    bool flag=false;
                    while(count>0){
                        steps++;
                        for(int k=0;k<count;k++){
                            pair<int,int> p=q.front();
                            q.pop();
                            solve(p,grid,s,q,n,flag);
                            if(flag==true){
                                ans=max(ans,steps);
                                break;
                            }
                        }
                        if(flag==true){
                            break;
                        }
                        count=q.size();
                    }
                }
            }
        }
        if(ans==INT_MIN){
            return -1;
        }
        return ans;
    }
    void solve(pair<int,int> p,vector<vector<int>>& grid,set<pair<int,int>>& s,queue<pair<int,int>>& q,int n,bool& flag){
        int x=p.first;
        int y=p.second;
        if(x-1>=0){
            if(grid[x-1][y]==1){
                flag=true;
                return;
            }
            else if(grid[x-1][y]==0 && s.find({x-1,y})==s.end()){
                q.push({x-1,y});
                s.insert({x-1,y});
            }
        }
        if(x+1<n){
            if(grid[x+1][y]==1){
                flag=true;
                return;
            }
            else if(grid[x+1][y]==0 && s.find({x+1,y})==s.end()){
                q.push({x+1,y});
                s.insert({x+1,y});
            }
        }
        if(y-1>=0){
            if(grid[x][y-1]==1){
                flag=true;
                return;
            }
            else if(grid[x][y-1]==0 && s.find({x,y-1})==s.end()){
                q.push({x,y-1});
                s.insert({x,y-1});
            }
        }
        if(y+1<n){
            if(grid[x][y+1]==1){
                flag=true;
                return;
            }
            else if(grid[x][y+1]==0 && s.find({x,y+1})==s.end()){
                q.push({x,y+1});
                s.insert({x,y+1});
            }
        }
    }
};
