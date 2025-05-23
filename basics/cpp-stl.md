# maps
std::map is implemented as a balanced binary search tree (usually a Red-Black Tree)
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
- when `if (!m[key)` is used, {key,0} pair is created in map which ruins map.size()

## erase
- `map[key]=0` set the val to 0, but does not remove the key
- `map.erase(key)` erases it

## ordered vs unordered maps
- ordered (order is maintained) using tree
  - insertion - logn
  - lookup - logn
- unordered
  - insertion - O(1) best case | O(N) average,worst case
  - lookup - O(1) best case | O(N) average,worst case
 
## desceding order map
`map<int,int, greater<int>> mp;`

## accessig the first element
- after a map is sorted use
- `mp.begin()->first; // used to get first key`
- cannot use (mp.begin() + n)->first to access the nth elements because they are not vectors and implemented as binary trees
- instead use this
```
auto it = mp.begin();
std::advance(it, n);
auto key = it->first;
```
  
# strings
- reversing string
```
    reverse(str.begin(), str.end())
        //no return type
    swap(s[i], s[n-i])
    string s = string(s.rbegin(), s.rend())
        //returns a string
    substrings

    s.subtr(start, no. of letters)

    string to int -> stoi() 7. int to string to_string() // negative indexing might not throw error but arr[-1] does NOT return last elemeen // instead takes you 4 bytes(size of last element) back from arr[0]
```
- stoi(str) - string to int
- to_string(num) int to string
- string(len, char)
  ```
  //to_string doesnt work on chars, ie to_string('c') !="c"
  string s(1,'c')
  ``` 
- so use
- substr(pos, no. of items) --> STRING SLICING
```
string str;
str.substr(3, 2); // pos, no of items
str.substr(pos); //everything *after* a pos
```
- s.erase(pos) - can erase at a position or in a range
- pop_back() in string to remove last character
- push_back() in string to all last character
- islower(char) & isupper(char) - checking if chars r upper or lowercase
- toupper(char) & tolower(char)
```cpp
char c = toupper('a'); // if char type not specified, it returns int of
char c2 = tolower('A');
```
- strtok
- string erase overloaded func (https://www.geeksforgeeks.org/stdstringerase-in-cpp/)
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
- getline: to get a complete line as input
```
string str;
getline(cin, str);
```
- isstream
```
stringstream iss(str);
while (iss >> word) {
    // word oper
    cout << word << '\n';
}
```
- string interpolation
```cpp
    // The first placeholder is represented by {0} and is replaced by 
       string s = format( "My name is {1} and my favorite number is {0}", num, name);
```
## append(no. of times, character)
```cpp
string ans="";
map<char, int> m;
for (auto x : m) ans.append(m[x], x);
```

# set
- implemented as a Red Black Tree (thus worst case is O(log n))
- ordered by default in cpp
- contain only unique values
- s.find(val) returns an interator to where element is found (if not found s.find(val)==s.end())
- can't use `s.find(val)-s.begin()` to get index unlike using vectors
- use this instead `distance(s.begin(), it)` takes O(n)
## unordered_set
- insert(), erase(), find() - O(1) average, O(N) worst
## set functions
- insert() - O(logN)
- erase(position)	- O(1)
- erase(value) - O(logN)
- erase(first, last) - O(N)
- clear() - O(N)
- swap() - constant
- find(val) - O(log N) 
# multiset
```
multiset<ll> s;
s.insert(k);
auto it = s.upper_bound(k);
s.erase(it);
```
multiset erase takes O(m) time complexity, m being the number of elements in a set vector erase takes O(n) time complexity since elements have to be shifted by one position

# dequeue
front()
back()
pop_front()
pop_back()
push_back()
push_front()

# count()
- number of times something appears
- `count(v.begin(), v.end(), k) //to count k;`

# priority queue
`priority_queue<a, b, c>` default is MAX heap
- a = data type of each element you will store in it
- b = pq is not a container, b is the container which will store the data elements
- c = greater<int> for min heap
```priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;```

# tuple
- tuples work in priority qeue min heap, `pair<pair<int,int>>` DOES NOT
```
tuple<int,int,int> my_tuple;
make_tuple(x,y,z);
get<0>(my_tuple); // can access using index
```
