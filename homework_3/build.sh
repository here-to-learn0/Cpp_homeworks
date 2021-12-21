mkdir build 
cd build
cmake ..
make
cd ..
./output > src/test.html
cd src
# xdg-open test.html
