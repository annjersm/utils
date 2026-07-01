# My utility library

- To build the project
```sh
cmake -S . -B build
```

- To compile the project
```sh
cmake --build build
```

- To install
```sh
cmake --install build
```

## Code Example
```c
vec3 foo = vec3(4, 0.5, 2);
vec3 bar = vec3(6, 0.1, 3);

// Vector + vector
vec3 sum = vec_mul(foo, bar);

// Vector + float (scalar)
vec3 sum = vec_mul(foo, 4.3f);
```

## Func:
```txt
                    2    3    4
matrix translate   [ ]  [x]  [ ]
matrix scale       [ ]  [x]  [ ]
matrix add         [ ]  [ ]  [ ]
matrix add_vec     [ ]  [ ]  [ ]
matrix sub         [ ]  [ ]  [ ]
matrix sub_vec     [ ]  [ ]  [ ]
matrix mul         [ ]  [ ]  [ ]
matrix mul_vec     [ ]  [ ]  [ ]
matrix div         [ ]  [ ]  [ ]
matrix div_vec     [ ]  [ ]  [ ]
vector add         [x]  [x]  [x]
vector div         [x]  [x]  [x]
vector mul         [x]  [x]  [x]
vector sub         [x]  [x]  [x]
vector cross       [ ]  [x]  [ ]
vector dot         [x]  [x]  [x]
vector length      [x]  [x]  [x]
vector normalize   [x]  [x]  [x]
vector print       [x]  [x]  [x]
```
