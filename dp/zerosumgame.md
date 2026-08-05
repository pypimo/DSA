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
