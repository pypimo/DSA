# Predict the Winner
https://leetcode.com/problems/predict-the-winner/

Initial Approach: https://leetcode.com/problems/predict-the-winner/solutions/8438820/dp-solution-thought-process-by-pypimo-787g/

For each turn, there is only one way to pick the best combination for the first player, so doesn't matter if we store the turn
i.e. dp[i][j][0] = abs(dp[i][j][1]) ALWAYS

If we store scores we would need 
```
int total = ps[j];
if (i-1>=0) total-=ps[i-1];
dp[i][j]= max(total-dp[i+1][j], total-dp[i][j-1]); 
```
If we store diff instead so simply dp[I][j] = something - dp[prev_i][[prev_j], because the prev value of B is actually just negative
```cpp
class Solution {
private:
    int dp[30][30]={0};
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        for (int i=n-1; i>=0; i--) {
            for (int j=0; j<n; j++) {
                if (i>j) continue;
                if (i==j) {dp[i][j]= nums[i]; continue;}
                if (i+1>n) dp[i][j]= max(nums[i]-dp[i+1][j], dp[i][j]);
                if () dp[i][j]= max(dp[i][j], nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1]>=0;
    }
};
```
# Stone game
same game but the number of piles is even, and number of stones is odd so no ties
so only an observation needed not dp
https://leetcode.com/problems/stone-game/description/

# Stone Game 3
Pick first 1,2,3 numbers of array
https://leetcode.com/problems/stone-game-iii/?envType=daily-question&envId=2026-08-03
```cpp
string stoneGameIII(vector<int>& nums) {
    int n=nums.size();
    // dp stores errors for 0-sum game
    for (int i=n-1; i>=0; i--) {
        dp[i]=INT_MIN;
        int val=0;
        for (int j=0; j<3 && i+j<n; j++) {
            val+=nums[i+j];
            dp[i] = max(dp[i], val-dp[i+j+1]);
        }
        cout << dp[i] << " ";
    }
    if (dp[0]>0) return "Alice";
    else if (dp[0]==0) return "Tie";
    return "Bob";
}
```
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
the ans keeps changing for each division so we should calculate all]
dp[i][j] = sum[i][j] + (score for min sum array)
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
