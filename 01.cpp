// Minimum Sum Partition.

class Solution{

  public:
	int minDifference(int arr[], int n)  {
	    // Your code goes here
	    int S=0;
	    for(int i=0;i<n;i++){
	        S+=arr[i];
	    }
	    int S1=solve(arr,n,S);
	    return S-2*S1;
	}
	int solve(int arr[],int n,int S){
	    bool t[n+1][S+1];
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=S;j++){
	            if(i==0){
	                t[i][j]=false;
	            }
	            if(j==0){
	                t[i][j]=true;
	            }
	        }
	    }
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=S;j++){
	            if(arr[i-1]<=j){
	                t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
	            }
	            else{
	                t[i][j]=t[i-1][j];
	            }
	        }
	    }
	    int ans=INT_MIN;
	    for(int j=0;j<=S/2;j++){
	        if(t[n][j]==true){
	            ans=j;
	        }
	    }
	    return ans;
	}
};
