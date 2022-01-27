// Find Largest Number in K swaps between digits of string.

class Solution
{
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans=str;
       string s=str;
       int n=k;
       for(int i=0;i<str.length();i++){
           int index=i;
           char ch=str[i];
           for(int j=i+1;j<str.length();j++){
               if(str[j]>ch){
                   ch=str[j];
                   index=j;
               }
           }
           if(index!=i){
               char temp=str[i];
               str[i]=str[index];
               str[index]=temp;
               n--;
           }
           if(n==0){
               break;
           }
       }
       n=k;
       for(int i=0;i<s.length();i++){
           int index=i;
           char ch=s[i];
           for(int j=s.length()-1;j>i;j--){
               if(s[j]>ch){
                   ch=s[j];
                   index=j;
               }
           }
           if(index!=i){
               char temp=s[i];
               s[i]=s[index];
               s[index]=temp;
               n--;
           }
           if(n==0){
               break;
           }
       }
       for(int i=0;i<str.length();i++){
           if(str[i]>s[i]){
               return str;
           }
           if(str[i]<s[i]){
               return s;
           }
       }
       return str;
    }


};
