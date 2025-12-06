# MonkeyWriter
A simple text editor that even a monkey can use!

# How to build (Linux)
## Step 1: Install Dependencies
```
sudo apt update
sudo apt install git cmake qt6-base-dev
```
## Step 2: Build It!
```
git clone https://github.com/Untitled312/MonkeyWriter.git
cd MonkeyWriter
cmake -B build
cd build
make
./MonkeyWriter
```
# How to build (Windows)
## Warning! Stable Work Isn't Guaranteed!
## Step 1: Install MSYS2
## Step 2: Install Dependencies
```
sudo pacman -Syu
sudo pacman -S base-devel git p7zip mc mingw-w64-x86_64-make \
mingw-w64-x86_64-ninja mingw-w64-clang-x86_64-tidy \
mingw-w64-x86_64-fmt mingw-w64-x86_64-toolchain \
mingw-w64-x86_64-cmake mingw-w64-x86_64-qt-creator \
mingw-w64-x86_64-clang
```
Don't forget to add Qt6 to PATH!
## Step 3: Build It!
```
git clone https://github.com/Untitled312/MonkeyWriter.git
cd MonkeyWriter
cmake -B build
cd build
ninja
./MonkeyWriter.exe
```
