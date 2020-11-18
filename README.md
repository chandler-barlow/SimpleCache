# Simple Cache
Hello! This is a small cache implementation. I plan on updating it to feature different replacement policies and the ability to cache from file streams.


## To compile and run
Linux/Mac
```
g++ ./main.cpp ./Cache.cpp ./LRU.cpp -o ./SimpleCache && ./SimpleCache
```
Windows
Make sure you are using the developer powershell for windows. Windows doesn't allow you to compile from the command line
```
cl ./main.cpp ./Cache.cpp ./LRU.cpp
./main.exe
```