class Solution {
public:

    int getLucky(string s, int k) {
        int sum=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            
            int sum=s[i]-'a'+1;
            while(sum>0){
                int temp=sum%10;
                ans+=temp;
                sum=sum/10;
            }
        }
        if(k==1){
            return ans;
        }
        int z=0;
        k=k-1;
        while(k>0){
            z=0;
            while(ans>0){
                int r=ans%10;
                z=z+r;
                ans=ans/10;
            }
            ans=z;
            k--;
        }
        
        return z;
    }
};