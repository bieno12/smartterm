# Lab12 GeoShape

## How to build

1. Clone the repository and enter its directory
```bash
git clone git@github.com:bieno12/smartterm.git
cd smartterm
```

2. Switch to the lab12 branch
```bash
git checkout lab12
```

3. Configure and build (out-of-source build recommended)
```bash
# create build directory and run CMake
mkdir -p build
cmake -S . -B build

# build the project
cmake --build build
```
4. Run smartterm excutable
```bash
cd build
./smartterm
```