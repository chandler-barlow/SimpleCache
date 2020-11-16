// Chandler Barlow
// 11/13/2020
// Logging system for cache hit or miss events
#include <vector>
#include <string>
#include <sstream>
class Event
{
    public:
    int address;
    int block_id;
    bool hit;
    Event(int address, int block_id, bool hit) : address{address}, block_id{block_id}, hit{hit} {}
};
class Logger
{
    private:
    std::vector<Event> event_list;
    public:
    void addEvent(int address, int block_id, bool hit)
    {
        Event temp_event(address, block_id, hit);
        event_list.push_back(temp_event);
    }
    std::string toString()
    {
        std::stringstream formatted_output;
        for(int i = 0; i < event_list.size(); i++)
        {
            Event temp_event = event_list.at(i);
            if(temp_event.hit)
            {
                formatted_output << "Hit! -";
            }
            else
            {
                formatted_output << "Miss! -";
            }
            formatted_output << " Address: " << temp_event.address << " , Block: " << temp_event.block_id << "\n";
        }
        return formatted_output.str();
    }
};