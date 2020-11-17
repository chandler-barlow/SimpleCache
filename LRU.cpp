#include <iostream>
#include <stdlib.h>
class Frame
{
    int length;
    int *frame = NULL;
    public:
    Frame(int length) : length{length}
    {
        frame = new int[length];
        for(int i = 0; i < length; i++)
        {
            frame[i] = i;
        }
    }
    // Returns the least used index of the cache set
    int getLeastUsed()
    {
        return frame[0];
    }
    // Sets a cache set index as recently used, pushing it to the back of the line
    void setRecentlyUsed(int indexInSet)
    {
        for(int i = 0; i < length - 1; i++)
        {
            if(frame[i] == indexInSet)
            {
                // If the current position in the frame holds the recently used index
                // Then the current position is swapped with the next
                // This will continue until the index is at the end of the list
                frame[i] = frame[i + 1];
                frame[i + 1] = indexInSet;
            }
        }
    }

};
class LRU
{
    const int frame_length;
    const int length;
    Frame *lru;
    public:
    LRU(int frame_length, int length) : frame_length{frame_length}, length{length}
    {
        lru = (Frame*) malloc(sizeof(Frame) * length);
        for(int i = 0; i < length; i++)
        {
            lru[i] = Frame(frame_length);
        }
    }
    int leastInFrame(int frameIndex)
    {
        return lru[frameIndex].getLeastUsed();
    }
    void updateRecentlyUsed(int frameIndex, int indexInSet)
    {
        lru[frameIndex].setRecentlyUsed(indexInSet);
    }
};