// Construct Quad Tree.

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        Node* Root=new Node();
        int p=solve1(0,0,n,n,grid);
        if(p==n*n){
            Root->isLeaf=true;
            Root->val=true;
            return Root;
        }
        else if(p==0){
            Root->isLeaf=true;
            Root->val=false;
            return Root;
        }
        else{
            Root->isLeaf=false;
            Root->val=false;
        }
        Node* root=Root;
        solve(0,0,n,n,grid,root);
        return Root;
    }
    void solve(int x,int y,int n,int m,vector<vector<int>>& grid,Node* root){
        int p1=solve1(x,y,n/2,m/2,grid);
        int p2=solve1(x,m/2,n/2,m,grid);
        int p3=solve1(n/2,y,n,m/2,grid);
        int p4=solve1(n/2,m/2,n,m,grid);
        if(p1==(n/2-x)*(n/2-x)){
            Node* t1=new Node(true,true);
            root->topLeft=t1;
        }
        else if(p1==0){
            Node* t1=new Node(false,true);
            root->topLeft=t1;
        }
        else{
            Node* t1=new Node(false,false);
            root->topLeft=t1;
            root=root->topLeft;
            solve(x,y,n/2,m/2,grid,root);
        }
        if(p2==(n/2-x)*(n/2-x)){
            Node* t1=new Node(true,true);
            root->topRight=t1;
        }
        else if(p2==0){
            Node* t1=new Node(false,true);
            root->topRight=t1;
        }
        else{
            Node* t1=new Node(false,false);
            root->topRight=t1;
            root=root->topRight;
            solve(x,m/2,n/2,m,grid,root);
        }
        if(p3==(n-n/2)*(n-n/2)){
            Node* t1=new Node(true,true);
            root->bottomLeft=t1;
        }
        else if(p3==0){
            Node* t1=new Node(false,true);
            root->bottomLeft=t1;
        }
        else{
            Node* t1=new Node(false,false);
            root->bottomLeft=t1;
            root=root->bottomLeft;
            solve(n/2,y,n,m/2,grid,root);
        }
        if(p4==(n-n/2)*(n-n/2)){
            Node* t1=new Node(true,true);
            root->bottomRight=t1;
        }
        else if(p4==0){
            Node* t1=new Node(false,true);
            root->bottomRight=t1;
        }
        else{
            Node* t1=new Node(false,false);
            root->bottomRight=t1;
            root=root->bottomRight;
            solve(n/2,m/2,n,m,grid,root);
        }
    }
    int solve1(int x,int y,int n,int m,vector<vector<int>>& grid){
        int sum=0;
        for(int i=x;i<n;i++){
            for(int j=y;j<m;j++){
                sum+=grid[i][j];
            }
        }
        return sum;
    }
};
