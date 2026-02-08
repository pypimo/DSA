- logic: you can match text and pattern character by chracter, if they dont you just start over with next begin index as i+1 in index
- but what if you already know some suffix string of pattern is also a prefix, so if suffix matches, then we can just start the matching after prefix]
- thus lps
- https://www.geeksforgeeks.org/dsa/kmp-algorithm-for-pattern-searching/ 

```cpp
int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        // lps
        int len=0,i=1,j=0,ans=0, m=pattern.size(), n=nums.size();
        lps[0]=0;
        while(i<m) {
            if (pattern[i]==pattern[len]) {
                len++;
                lps[i]=len;
                i++;
            } else if (!len) {
                lps[i]=0;
                i++;
            }
            else len=lps[--len];
        }

        // changing arr to pattern arr
        for (int i=0; i<n-1; i++) {
            if (nums[i]<nums[i+1]) nums[i]=1;
            else if (nums[i]>nums[i+1]) nums[i]=-1;
            else nums[i]=0;
        }

        // pattern matching
        i=0;
        while(i<n-1) {
            if (pattern[j]==nums[i]) {
                i++; j++;
            } else if (j) {
                j=lps[j-1];
            } else i++;

            if (j==m) {
                // if start position needed
                // ans.push_back(i-m+1)
                j=lps[j-1]; 
                ans++;
            }
        }    
        return ans;    
    }
```
