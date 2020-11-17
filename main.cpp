#include <iostream>
#include "Cache.cpp"



int main()
{
    Cache cache(8, 1);
    cache.cacheEvent(8);
    cache.cacheEvent(8);
    cache.cacheEvent(2);
    return 0;
}