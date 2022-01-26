// Word Search

class Solution {
public:
    void solve(int x,int y,int i,string& word,vector<vector<char>>& board,vector<vector<bool>>& vis,int n,int m,bool& flag){
        vis[x][y]=true;
        i++;
        if(i==word.length()){
            flag=true;
            return;
        }
        if(x-1>=0 && board[x-1][y]==word[i] && vis[x-1][y]==false){
            solve(x-1,y,i,word,board,vis,n,m,flag);
            if(flag==true){
                return;
            }
        }
        if(x+1<n && board[x+1][y]==word[i] && vis[x+1][y]==false){
            solve(x+1,y,i,word,board,vis,n,m,flag);
            if(flag==true){
                return;
            }
        }
        if(y-1>=0 && board[x][y-1]==word[i] && vis[x][y-1]==false){
            solve(x,y-1,i,word,board,vis,n,m,flag);
            if(flag==true){
                return;
            }
        }
        if(y+1<m && board[x][y+1]==word[i] && vis[x][y+1]==false){
            solve(x,y+1,i,word,board,vis,n,m,flag);
            if(flag==true){
                return;
            }
        }
        vis[x][y]=false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    bool flag=false;
                    solve(i,j,0,word,board,vis,n,m,flag);
                    if(flag==true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
