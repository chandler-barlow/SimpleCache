#include <iostream>
#include "Cache.cpp"
int main()
{
    NWayCache nc(8, 4);
    for(int i = 0; i < 9; i++)
    {
        int a;
        std::cout << "Enter an address: ";
        std::cin >> a;
        if(nc.insert_address(a) == 1)
        {
            std::cout << "Hit!\n";
        }
        else
        {
            std::cout << "Miss!\n";
        }
    }
    return 0;
}