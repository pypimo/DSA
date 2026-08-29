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
