#include <stdlib.h>
#include <sstream>
#include <string>
#include "LRU.cpp"
class Set
{
    private:
    int length;
    int *set;
    public:
    Set(int length) : length{length}
    {
        set = new int[length];
        // Everything initialized to trash value
        for(int i = 0; i < length; i++)
        {
            set[i] = -1;
        }
    }
    // Negative value means its a miss
    int hit(int address)
    {
        for(int i = 0; i < length; i++)
        {
            if(set[i] == address)
            {
                return i;
            }
        }
        return -1;
    }
    void update(int index, int address)
    {
        set[index] = address;
    }
    std::string toString()
    {
        std::stringstream ss;
        for (int i = 0; i < length; i++)
        {
            if(set[i] >= 0)
            {
                ss << set[i];
            }
            else
            {
                ss << "EMPTY";
            }
            if(i != length - 1)
            {
                ss << ", ";
            }
        }
        return ss.str();
    }
};
class Cache
{
    // Block count 
    int length;
    // Length of each set in cache
    int set_length; 
    // the actual cache object  
    Set *cache;
    // the lru object
    LRU *lru_p;
    public:
    Cache(int length, int set_length) : length{length/set_length}, set_length{set_length}
    {
        lru_p = new LRU(set_length, length);
        cache = (Set*)malloc(sizeof(Set) * length);
        for(int i = 0; i < length; i++)
        {
            cache[i] = Set(set_length);
        }
    }
    // Returns true if hit and false if miss
    bool poll_address(int address)
    {
        // cache_index == frame_index
        int cache_index = address % (length / set_length);
        int hit_index = cache[cache_index].hit(address);
        if(hit_index >= 0)
        {
            lru_p->updateRecentlyUsed(cache_index, hit_index);
            return true;
        }
        else
        {
            int lu_index = lru_p->leastInFrame(cache_index);     
            cache[cache_index].update(lu_index, address);
            lru_p->updateRecentlyUsed(cache_index, lu_index);
            return false;
        }
    }
    std::string toString()
    {
        std::stringstream ss;
        for(int i = 0; i < length; i++)
        {
            ss << "[ ";
            ss << cache[i].toString();
            ss << " ]\n";
        }
        return ss.str();
    }
    std::string cacheEvent(int address)
    {
        std::stringstream ss;
        if(poll_address(address))
        {
            ss << this->toString();
            ss << "~ HIT ~" << "\n";
        }
        else
        {
            ss << this->toString();
            ss << "~ MISS ~\n";
        }
        return ss.str();
    }

};
class DirectCache : public Cache
{
    DirectCache(int length) : Cache(length, 1) {}
};
class TwoWayCache : public Cache
{
    TwoWayCache(int length) : Cache(length, 2) {}
};
class FourWayCache : public Cache
{
    FourWayCache(int length) : Cache(length, 4) {}
};
class FullCache : public Cache
{
    FullCache(int length) : Cache(length, length) {}
};