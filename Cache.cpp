#include <vector>

// Each set has an Id which is its location in the cache
// The n value is the amount of possible elements in the set
// The replacement policy is LRU !IMPORTANT!
class Set
{
    private:
    int id;
    // Amount of memory blocks per set in cache
    int n;
    // Each set of the cache
    std::vector<int> addresses;
    public:
    Set(int id) : id{id} {}
    // Get the ID of the set
    int getId()
    {
        return id;
    }
    // Get the list of all the addresses
    std::vector<int> getSet()
    {
        return addresses;
    }
    // Insert an address into the set
    void insert_address(int address)
    {
        if(addresses.size() == n)
        {
            addresses.erase(addresses.begin(), addresses.begin() + 1);
            addresses.push_back(address);
            return;
        }
        if(addresses.size() < n)
        {
            addresses.push_back(address);
        }
    }
};

class Cache
{
    private:
    int n;
    std::vector<Set> cache;
    
    public:
    Cache(int n) : n{n} {}

    void push_set(int id, int address)
    {
        Set new_set(id);
        new_set.insert_address(address);
        cache.push_back(new_set);
    } 
};



