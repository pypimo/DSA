## libraries (use #include)
- iostream
- math.h
- string

## using namespace std;
- without this, use `std::cout << "HELLO";`
- writing this, std is used for all functions

## <bits/stdc++.h>
- includes all the libraries in c++

## comments //

## data types
- int -1e9 to 1e9
- long -1e12 to 1e12
- long long -1e18 to 1e18
- float 1e38
- double 1e308
- long double 2e4932
- string separated by space and endline
```
string s;
cin >> s;
cout << s;
```
- to get the complete string (only separated by endline)
`string s;
getline(cin, s);
cout << s;`
- for single character -> use char takes less space (256 characters)

## switch
```
int day;
cin >> day;
switch(day) {
  case 1:
    cout << "Monday";
  case 2:
    cout << "Tuesday";
  case 3:
    cout << "Wednesday";
  case 4:
    cout << "Thursday";
  case 5:
    cout << "Friday";
  case 6:
    cout << "Saturday";
  case 7:
    cout << "Sunday";
  cout << "Hello World"; //not executed, if switch statement has break keyword
  default:
    cout << "invalid";
  // without break, everything is executed in sequence
}
// if a  case is found to be true, everything after that is true
// thus, need to add break statements after every case
```
## array
- only same kind of data can be stored `int arr[5];` if any element is double, will trim itself to be int
- 2D `int arr

## string 
- len of string
```
string s;
cin >> s;
cout << s.size(); // length of string
```

## loops 
- while
- for / nested for
- do-while


## functions (flow goes to the function)
- void
- non-void (MUST ALWAYS have a return type) --> else returns a garbage value 
- parameterised
- non-parameterised
- passing by reference -->

## sort
- has no return value

  ## ascii code: a --> 65, A --> 97

## round()
to round down

## stoi()
https://www.geeksforgeeks.org/stdstoi-function-in-cpp/
converts string to num, string s = stoi(num);

## min({1,2,3})
min of multiple values

## min_element(arr, arr+n)
min element of multiple values

## typeid(variable).name()
get type of variable, Pc = pointer

## pop_back vs back()
pop_back just removes the last member from the vector but it doesnt return anything
thus, cant do: cout << v.pop_back();

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

# multimap
- multiple elements can have the same keys
- m[key] = value doesnt work
- use instead m.insert({key,value});
- default ascedning order sort
- sort in desc -> multimap<int,char, greater<int>>

