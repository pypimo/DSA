# Stone Game 2 
https://leetcode.com/problems/stone-game-ii/description/

Number of picks can go between x to 2m, and m on each iteration can be max(m, x+1);
So dp state is i,x
Final ans needs to be score, but we can store the diff
A+B=total, A-B=diff
So A  = (diff+total)/2
```cpp
  nt dp[10010][110];
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
