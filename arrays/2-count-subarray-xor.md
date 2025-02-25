https://www.interviewbit.com/problems/subarray-with-given-xor/

- use map to count xor till every arr[i]
- let curr xor = x and intended xor = B
- so we need to find y in initial part of array such that
- x^y = B same as x^B = y
- thus count x^B in map and add to ans

```cpp
int Solution::solve(vector<int> &A, int B) {
    //x^y=k
    //x^k=y // count these
    map<int,int> mp;
    mp[0]++;
    int xor_tot=0, ans=0, n=A.size();
    for (int i=0; i<n; i++) {
        xor_tot^=A[i];
        ans += mp[xor_tot^B];
        mp[xor_tot]++;
    }
    return ans;
}
```
