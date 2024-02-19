# maps
## multimap

    multiple elements can have the same keys
    m[key] = value doesnt work
    use instead m.insert({key,value});
    default ascedning order sort
    sort in desc -> multimap<int,char, greater>

## count()
```
map<int,int> m;
m.count(k); // returns the no. of times key k is present
```
- can be used when one wants to check if a key is present and m[k] might be 0
- so if (m.count(k) && m[k]!=val...) {do..}

## ordered vs unordered maps
- ordered (order is maintained) using tree
  - insertion - logn
  - lookup - logn
- unordered
  - insertion - O(1) best case | O(N) average,worst case
  - lookup - O(1) best case | O(N) average,worst case

# strings
## reversing string
```
    reverse(str.begin(), str.end())
        no return type
    swap(s[i], s[n-i])
    string s = string(s.rbegin(), s.rend())
        returns a string
    substrings

    s.subtr(start, no. of letters)

    string to int -> stoi() 7. int to string to_string() // negative indexing might not throw error but arr[-1] does NOT return last elemeen // instead takes you 4 bytes(size of last element) back from arr[0]
```
## stoi(str) - string to int
## to_string(num) - int to string
## substr(pos, no. of items) --> STRING SLICING
```
string str;
str.substr(3, 2); // pos, no of items
str.substr(pos); //everything *after* a pos
```
## toupper() & tolower()
char c = toupper('a'); // if char type not specified, it returns int of
char c2 = tolower('A');
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

# multiset
```
multiset<ll> s;
s.insert(k);
auto it = s.upper_bound(k);
s.erase(it);
```
multiset erase takes O(m) time complexity, m being the number of elements in a set vector erase takes O(n) time complexity since elements have to be shifted by one position
