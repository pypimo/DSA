https://bit.ly/3zWZoCs

## Using equations
```cpp
vector<int> findTwoElement(vector<int>& arr) {
        ll n = arr.size(), sum_n = n*(n+1)/2, sq_n = (n*(n+1)*(2*n+1))/6 ,sum_arr = 0, sq_arr=0, sum,diff;
         
        for (int i=0; i<n; i++) sum_arr += (ll)arr[i];
        for (int i=0; i<n; i++) sq_arr += (ll)arr[i]*(ll)arr[i];
        diff= sum_arr-sum_n;
        sum = (sq_arr-sq_n)/diff ;
        ll A= (sum+diff)/2 ;
        ll B= sum-A;
        return {(int)A,(int)B};
    }
```

## Using XOR
```cpp
vector<int> findTwoElement(vector<int>& arr) {
        // make two groups of nos
        // A^B = xor of all nums
        int xor_tot=0, ind=0, n=arr.size();
        for (int i=0; i<n; i++) {
            xor_tot^=arr[i]^(i+1);
        }
        // find first rightmost bit
        for (int i=0; i<31; i++) {
            if ((xor_tot>>i) & 1==1) {
                ind=i;
                break;
            }
        }
        int a=0, b=0;
        for (int i=0; i<n; i++) {
            if (((i+1)>>ind) & 1==1) a^=(i+1);
            else b^=(i+1);
            if ((arr[i]>>ind) & 1==1) a^=arr[i];
            else b^=arr[i];
        }
        for (int i=0; i<n; i++) {
            if (arr[i]==a) return {a,b};
            if (arr[i]==b) return {b,a};
        }
    }
```
