https://leetcode.com/problems/predict-the-winner/

My Initial Solution: https://leetcode.com/problems/predict-the-winner/solutions/8438820/dp-solution-thought-process-by-pypimo-787g/

For each turn, there is only one way to pick the best combination for the first player, so doesn't matter if we store the turn
i.e. dp[i][j][0] = abs(dp[i][j][1]) ALWAYS

If we store scores we would need (total[I][j] - dp[I][j]) as the sum of A previously, alternating and total[I][j] = ps[j]-ps[I-1]
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
                dp[i][j]= max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]); 
            }
        }
        return dp[0][n-1]>=0;
    }
};
```
