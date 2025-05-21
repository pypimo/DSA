https://leetcode.com/problems/painting-a-grid-with-three-different-colors
- cell level dp is too naive, because you can't use `sum` or `max` of any combinations without seeing the path history
- the adjacency constraints affect whole rows and columns
- instead make a validCol that stores col patterns that are valid
- then for each col, check the previous col patterns and add
```
class Solution {
public:
    int m = 1e9+7;
    bool compare(vector<int>& a, vector<int>& b) {
        for (int ind=0; ind<a.size(); ind++) {
            if (a[ind]==b[ind]) return false;
        }
        return true;
    }
    int add(int a, int b){
        return (a+b)%m;
    }
    int colorTheGrid(int m, int n) {
        vector<vector<int>> validCol;
        for (int i=0; i<pow(3,m); i++) {
            int num=i, flag=1;
            vector<int> col;
            for (int j=0; j<m; j++) {
                col.push_back(num%3);
                num/=3;
                if (j && col[j]==col[j-1]) {
                    flag=0;
                    break;
                } 
            }
            if (flag) validCol.push_back(col);
        }
        int cols = validCol.size();
        vector<vector<int>> dp(n,vector<int>(cols,0));
        for (int j=0; j<cols; j++) {
            dp[0][j] = 1;
        }
        for (int i=1; i<n; i++) {
            for (int j=0; j<cols; j++) {
                for (int k=0; k<cols; k++) {
                    if (compare(validCol[j], validCol[k])) dp[i][j]=add(dp[i][j], dp[i-1][k]);
                }
            }
        }

        int sum=0;
        for (int j=0; j<cols; j++) sum=add(sum, dp[n-1][j]);
        return sum;
    }
};
``` 
