## reversing string
1. reverse(str.begin(), str.end())
   - no return type
3. swap(s[i], s[n-i])
4. string s = string(s.rbegin(), s.rend())
   - returns a string
5. substrings
 - s.subtr(start, no. of letters)
6. string to int -> stoi()
   7. int to string to_string()
// negative indexing might not throw error but arr[-1] does NOT return last elemeen
// instead takes you 4 bytes(size of last element) back from arr[0]

# string methods

## to_string
converts num to string, so string s = to_string(num);

## substr(pos, no. of items)  --> STRING SLICING
```
string str;
str.substr(3, 2); // pos, no of items
str.substr(pos); //everything *after* a pos

```
## toupper() & tolower()
```
char c = toupper('a'); // if char type not specified, it returns int of
char c2 = tolower('A');
```

## strtok
https://www.geeksforgeeks.org/strtok-strtok_r-functions-c-examples/
```
char str[] = "Geeks-for-Geeks";
char* token = strtok(str, " - ");
 
while (token != NULL) {
 cout << token << " ";
  token = strtok(NULL, " - ");
  
  // get the next token i.e. word before second empty space
  // NULL indicates we are using the same pointer we used previously i.e. quote
}
```

## reverse a string
```
string s = "gsgfs";
reverse(s.begin(), s.end());
cout << s;
```

# multiset
```
multiset<ll> s;
s.insert(k);
auto it = s.upper_bound(k);
s.erase(it);
```

# s.erase()
multiset erase takes O(m) time complexity, m being the number of elements in a set
vector erase takes O(n) time complexity since elements have to be shifted by one position

