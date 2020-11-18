// chandler barlow
#include <iostream>
#include "Cache.cpp"
int main()
{
    int cache_length = 0;
    int n = 0;
    int address = 0;
    std::cout << "How many blocks are in the cache?: ";
    std::cin >> cache_length;
    std::cout << "What is the set assosciativity?: \n";
    std::cout << "0 == Fully\n" << "1 == Direct\n" << "2 == TwoWay\n" << "4 == FourWay\n" << "Or enter your own number\n" << "-> ";
    std::cin >> n;
    if(n == 0)
    {
        n = cache_length;
    }
    Cache cache(cache_length, n);
    bool loop = true;
    while(loop)
    {
        int a;
        std::cout << "Enter an address: ";
        std::cin >> a;
        std::cout << cache.cacheEvent(a);
        std::cout << "continue? \n1 == yes \n0 == no \n->";
        std::cin >> a;
        if(a == 0)
        {
            loop = false;
            std::cout << "printing final state: \n";
            cache.toString();
        }
    }
    return 0;
}