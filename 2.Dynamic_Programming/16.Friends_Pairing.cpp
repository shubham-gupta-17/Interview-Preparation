int *dp;
int find(int i,bool *vis,int n){
    if(i==n+1){
        return 1;
    }
    if(dp[i]!=-1) return dp[i];
    if(vis[i]) return dp[i]=find(i+1,vis,n);
    else {
        vis[i]=true;
        int count=0;
        count = find(i+1,vis,n);
        for(int j=i+1;j<=n;j++){
            if(vis[j]) continue;
            vis[j]=true;
            count+=find(i+1,vis,n);
            vis[j]=false;
        }
        vis[i]=false;
        return dp[i] =count;
    }
    
    return 0;
}
    int countFriendsPairings(int n) {
        dp=new int[n+1]();
    //     int mod=(int )1e9+7;
    // for (int i = 0; i <= n; i++) { 
    //     if (i <= 2) 
    //         dp[i] = i; 
    //     else
    //         dp[i] = ((dp[i-1]) + ((i-1)*dp[i-2]))%mod;
        
    //     if(dp[i]<0) dp[i]+=mod;
    // } 
  
    // return dp[n]; 
    
    for(int i=0;i<=n;i++) dp[i]=-1;
    dp[0]=0;
    bool *vis=new bool[n+1]();
    return find(1,vis,n);
    }