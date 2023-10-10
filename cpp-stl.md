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
str.substr(3, 2);
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
cout << reverse(s.begin(), s.end()); // way1
cout << strrev(s.begin(), s.end()); //way2
```
