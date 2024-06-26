
string findLCS(int n, int m,string &s1, string &s2){

    // Write your code here.    

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

   s1 = "#" + s1;
        s2 = "#" + s2;
        dp[0][0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
        }
    }
    string res = "";
    int i = n;
    int  j = m;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            res = s1[i-1]+res;
            i--; 
            j--;
        }
    else if(dp[i-1][j] >= dp[i][j-1])     i--;
        else  j--;
    }

    return res;

}}
