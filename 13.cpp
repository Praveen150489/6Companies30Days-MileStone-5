//  Minimum Swaps to Arrange a Binary Grid.

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> v,v1;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0){
                    count++;
                }
                else{
                    break;
                }
            }
            v.push_back(count);
            v1.push_back(count);
        }
        sort(v1.begin(),v1.end());
        reverse(v1.begin(),v1.end());
        for(int i=0;i<n;i++){
            if(v1[i]<n-1-i){
                return -1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(v[i]<n-1-i){
                int index=-1;
                for(int j=i+1;j<n;j++){
                    if(v[j]>=n-1-i){
                        index=j;
                        break;
                    }
                }
                while(index>i){
                    int temp=v[index];
                    v[index]=v[index-1];
                    v[index-1]=temp;
                    ans++;
                    index--;
                }
            }
        }
        return ans;
    }
};
