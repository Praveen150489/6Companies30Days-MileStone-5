// Capacity To Ship Packages Within D Days.

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            sum+=weights[i];
        }
        int l=0;
        int h=sum;
        int ans=INT_MAX;
        while(l<=h){
            int mid=(l+h)/2;
            int count=0;
            int s=0;
            bool flag=true;
            for(int i=0;i<n;i++){
                if(weights[i]>mid){
                    flag=false;
                    break;
                }
                else if(s+weights[i]<mid){
                    s+=weights[i];
                }
                else if(s+weights[i]>mid){
                    count++;
                    s=weights[i];
                    if(count>days){
                        flag=false;
                        break;
                    }
                }
                else if(s+weights[i]==mid){
                    count++;
                    s=0;
                    if(count>days){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag==true){
                if(s>0){
                    count++;
                }
                if(count<=days){
                    ans=min(ans,mid);
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
