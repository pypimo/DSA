# Stone Game 2 
https://leetcode.com/problems/stone-game-ii/description/

Number of picks can go between x to 2m, and m on each iteration can be max(m, x+1);
So dp state is i,x
Final ans needs to be score, but we can store the diff
A+B=total, A-B=diff
So A  = (diff+total)/2
```cpp
int dp[10010][110];
int stoneGameII(vector<int>& piles) {
  int n = piles.size(), total=0;;
  for (int i=n-1; i>=0; i--) {
      total+=piles[i];
      for (int m=1; m<=n; m++) {
          dp[i][m] = INT_MIN;
          int sum=0;
          for (int x=0; x<2*m && i+x<n; x++) {
              sum+=piles[i+x];
              int sub=0;
              if (i+x+1<n) sub = dp[i+x+1][max(x+1,m)];
              dp[i][m] = max(dp[i][m], sum-sub);
          }
          // cout << i << " " << m << " " << dp[i][m] << '\n';
      }
  }
  int ans = (total + dp[0][1])/2;
  return ans;
```

# Stone Game V
https://leetcode.com/problems/stone-game-v

```cpp
int dp[510][510];
int stoneGameV(vector<int>& stoneValue) {
  int n = stoneValue.size();
  vector<int> sum(n,0);
  sum[0]=stoneValue[0];
  for (int i=1; i<n; i++) sum[i]=stoneValue[i]+sum[i-1];
  for (int i=n-1; i>=0; i--) {
      for (int j=i+1; j<n; j++) {
          // if (i==j) continue;
          for (int k=i; k<j; k++) {
              int sum1 = sum[k], sum2 = sum[j]-sum[k];
              if (i-1>=0) sum1-=sum[i-1];
              int val=0; //score for non-discarded portion
              if (sum1>sum2) val = dp[k+1][j];
              else if (sum2>sum1) val = dp[i][k];
              else val=max(dp[k+1][j], dp[i][k]);
              dp[i][j] = max(dp[i][j], val+min(sum1,sum2));
          }
         
      }
  }
  return dp[0][n-1];
}
```
