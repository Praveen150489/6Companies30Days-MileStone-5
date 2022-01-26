// Split Array Largest Sum.

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int l=0;
        int h=sum;
        int ans=INT_MAX;
        while(l<=h){
            int mid=(l+h)/2;
            int count=0;
            int s=0;
            bool flag=true;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>mid){
                    flag=false;
                    break;
                }
                else if(s+nums[i]<mid){
                    s+=nums[i];
                }
                else if(s+nums[i]>mid){
                    count++;
                    s=nums[i];
                    if(count>m){
                        flag=false;
                        break;
                    }
                }
                else if(s+nums[i]==mid){
                    count++;
                    s=0;
                    if(count>m){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag==true){
                if(s>0){
                    count++;
                }
                if(count<=m){
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
