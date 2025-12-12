## from 1 to N
- N is positive
<img width="573" height="427" alt="chrome_E8StlrXpMi" src="https://github.com/user-attachments/assets/d52763d6-f97f-41f6-ba25-08233599fa83" />
<img width="886" height="299" alt="chrome_Gjio6KvdsP" src="https://github.com/user-attachments/assets/94287560-f5ea-4141-be8b-550af445b7a5" />

## from L to R
func (R) - func(L-1)

## find a^b <= lim such that a,b E [L,R]
- Given integers lo, hi, and k (with lo < hi ≤ 1e4 and k ≤ 1e4), find max( a XOR b ) subject to:
- lo ≤ a < b ≤ hi
- (a XOR b) ≤ k
- Return the largest XOR value ≤ k achievable by any pair (a, b) in the range [lo, hi].
```cpp
int maxXor(int lo, int hi, int k) {
    int result = 0;

    // Try to turn on bits from MSB down to LSB
    for (int bit = 14; bit >= 0; bit--) {  // since k <= 1e4 < 2^14
        int candidate = result | (1 << bit);

        if (candidate > k) continue;  // can't exceed k

        bool ok = false;
        int X = candidate;

        // Check if there exists a pair (a, b)
        // such that a XOR b = X and both in [lo, hi]
        for (int a = lo; a <= hi; a++) {
            int b = a ^ X;
            if (b >= lo && b <= hi && b != a) {
                ok = true;
                break;
            }
        }

        if (ok)
            result = candidate;  // keep this bit turned on
    }

    return result;
}
```
