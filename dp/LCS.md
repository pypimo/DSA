# Longest Common Substring
- substring needs to be continuous
- so if string i,j match then dp[i][j] is dp[i-1][j-1] + 1
- else dp[i][j] is 0
- base states dp[0][0], dp[i][0], dp[0][j]
- ans is max of dp[i][j]

# Longest Common Subsequence
- Subsequence can be discontinuous
- so if string i,j match then dp[i][j] is dp[i-1][j-1] + 1
- else dp[i][j] is max(dp[i-1][j], dp[i][j-1])
- base states dp[0][0], dp[i][0], dp[0][j]
- ans is dp[n][m]
```cpp
// or make it one based index
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}
```
