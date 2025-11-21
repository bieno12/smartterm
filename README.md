# Lab5 Employee Add and Display

## How to build

1. Clone the repository and enter its directory
```bash
git clone git@github.com:bieno12/smartterm.git
cd smartterm
```

2. Switch to the lab5 branch
```bash
git checkout lab5
```

3. Configure and build (out-of-source build recommended)
```bash
# create build directory and run CMake
mkdir -p build
cmake -S . -B build

# build the project
cmake --build build
```
4. Run the smartterm For Add and List Employee Task
```bash
cd build
./smartterm
```
5. Run the swap_task 
```bash
./swap_task/swap_task
```
6. Run the 2d array task
```bash
./2d_array_task/array_task
```