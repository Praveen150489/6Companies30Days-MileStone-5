// Koko Eating Bananas.

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int L=1;
        int H=1000000000;
        int ans=INT_MAX;
        while(L<=H){
            int mid=(L+H)/2;
            int time=0;
            bool flag=true;
            for(int i=0;i<piles.size();i++){
                if(piles[i]%mid==0){
                    time+=piles[i]/mid;
                }
                else{
                    time+=(piles[i]/mid + 1);
                }
                if(time>h){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                ans=min(ans,mid);
                H=mid-1;
            }
            else{
                L=mid+1;
            }
        }
        return ans;
    }
};
