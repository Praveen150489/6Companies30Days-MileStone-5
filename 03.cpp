// Find missing number in a string.

int missingNumber(const string& str)
{
    // Code here
    int l=1;
    int ans=-1;
    while(l<=6 && str.length()>=l){
        bool flag=true;
        int count=0;
        int ans1=-1;
        int n=0;
        for(int i=0;i<l;i++){
            n=n*10 + (str[i]-'0');
        }
        int m=0;
        int k=l;
        while(k<str.length()){
            m=m*10+(str[k]-'0');
            if(m>n){
                if(m-n==1){
                    n=m;
                    m=0;
                }
                else if(m-n==2){
                    count++;
                    ans1=n+1;
                    n=m;
                    m=0;
                }
                else{
                    flag=false;
                    break;
                }
            }
            k++;
        }
        if(flag==true && count==1 && m==0){
            ans=ans1;
            return ans;
        }
        l++;
    }
    return ans;
}
