# Lab6 Text Editor

## How to build

1. Clone the repository and enter its directory
```bash
git clone git@github.com:bieno12/smartterm.git
cd smartterm
```

2. Switch to the la6 branch
```bash
git checkout lab7
```

3. Configure and build (out-of-source build recommended)
```bash
# create build directory and run CMake
mkdir -p build
cmake -S . -B build

# build the project
cmake --build build
```
4. Run test_string excutable
```bash
cd build
./test_string/test_string
```
5. Run python_list excutable
```bash
cd build
./python_list/python_list
```
6. Run complex excutable
```bash
cd build
./complex/complex
```