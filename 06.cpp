// Find in Mountain Array.

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l=0;
        if(mountainArr.get(0)==target){
            return 0;
        }
        int h=mountainArr.length()-1;
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            int x=mountainArr.get(mid);
            int y=-1;
            if(mid-1>=0){
                y=mountainArr.get(mid-1);
            }
            int z=-1;
            if(mid+1<mountainArr.length()){
                z=mountainArr.get(mid+1);
            }
            if(x>y && x>z){
                ans=mid;
                break;
            }
            if(x>y){
                ans=mid;
                l=mid+1;
            }
            if(x<y){
                h=mid-1;
            }
        }
        if(mountainArr.get(ans)==target){
            return ans;
        }
        l=0;
        h=ans;
        while(l<=h){
            int mid=(l+h)/2;
            int x=mountainArr.get(mid);
            if(x==target){
                return mid;
            }
            if(x<target){
                l=mid+1;
            }
            if(x>target){
                h=mid-1;
            }
        }
        h=mountainArr.length()-1;
        l=ans;
        while(l<=h){
            int mid=(l+h)/2;
            int x=mountainArr.get(mid);
            if(x==target){
                return mid;
            }
            if(x<target){
                h=mid-1;
            }
            if(x>target){
                l=mid+1;
            }
        }
        h=mountainArr.length()-1;
        if(mountainArr.get(h)==target){
            return h;
        }
        return -1;
    }
};
