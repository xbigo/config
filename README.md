# Config

C++ compiler, OS, and standard library detect

## Build

For Mac and Linux:

```bash
git clone https://github.com/xbigo/config.git
mkdir ../build
cd ../build
cmake -S ../config -D BUILD_TESTING=1
make
make check
make install
```

For MSVC:

```bat
git clone https://github.com/xbigo/config.git
mkdir ../build
cd ../build
cmake -S ../config -D BUILD_TESTING=1
cmake --build .
cmake --build . --target check
cmake --build . --target install
```

