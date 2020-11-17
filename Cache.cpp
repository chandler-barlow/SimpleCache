class Cache
{
    protected:
    int length;
    int n;
    int *cache;
    int *LRU;
    int contains(int value, const int (&list)[], int length)
    {
        for(int i = 0; i < length; i++)
        {
            if(list[i] == value)
            {
                return i;
            }
        }
        return -1;
    }
    public:
    Cache(int length) : length{length} 
    {
        cache = new int[length];
    }
};
class NWayCache : public Cache
{
    private:
    int n;
    public:
    NWayCache(int length, int n) : Cache(length), n{n} 
    {
        LRU = new int[length/n];
    }
    int insert_address(int address)
    {
        for(int i = 0; i < n - 1; i++)
        {
            if()
        }
        else
        {
            LRU
        }
        // ERROR IF -1
        return -1;
    }
};
class DirectCache : public NWayCache
{
    public:
    DirectCache(int length) : NWayCache(length, 1) {}
};
/**
class FullCache : public NWayCache
{
    public:
    FullCache(int length) : 

};
**/