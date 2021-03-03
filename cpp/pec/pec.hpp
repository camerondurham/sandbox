#include<vector>
#include<queue>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<map>
#include<algorithm>
#include<chrono>

using std::chrono::time_point;
using std::chrono::steady_clock;
using std::string;
using std::vector;


class PriorityExpiryCache
{

public:
    PriorityExpiryCache(){}
    PriorityExpiryCache(int capacity);
    ~PriorityExpiryCache();
    struct Item {
        string mData;
        int mPriority;
        // for usage, see here: std::https://en.cppreference.com/w/cpp/chrono/steady_clock/now
        std::chrono::time_point<steady_clock> mExpiryTime;

        int* mExpiryIndex;
        int* mPriorityIndex;
        Item(string data, int priority, std::chrono::time_point<steady_clock> expireTime, int* expiryIndex, int* priorityIndex)
                :mData(data)
                ,mPriority(priority)
                ,mExpiryTime(expireTime)
                ,mExpiryIndex(new int)
                ,mPriorityIndex(new int)

        {
            mExpiryIndex = expiryIndex;
            mPriorityIndex = priorityIndex;
        }

    };

    void Set(string key, string value, int priority, int expireTime);
    Item* Get(string key);
    void SetMaxItems(int maxItems);

private:
    int capacity;
    std::map<string, PriorityExpiryCache::Item*> items;

    std::map<int, vector<string>> expireItems;
    std::map<std::chrono::time_point<steady_clock>, int*> expiryIndexMap;

    std::map<int, vector<string>> priorityItems;
    std::map<int, int*> priorityIndexMap;

    void evictItems(int currentTime);
    void remove(string key);
};

PriorityExpiryCache::PriorityExpiryCache(int capacity)
{
    capacity = capacity;
}

PriorityExpiryCache::~PriorityExpiryCache()
{
    for(auto it = items.begin(); it != items.end(); it++)
    {
//        delete it->second;
    }
}

void PriorityExpiryCache::Set(string key, string value, int priority, int expireTime)
{
    if(items.find(key) != items.end()) {
        remove(key);
    }
    // TODO: add indices somehow?
    auto item = new Item(value, priority, expireTime);
    if (expireItems.find(expireTime) == expireItems.end()) {
//            vector<string> keys = {key};
//            expireItems[expireTime] = keys;
    } else {
        expireItems[expireTime].push_back(key);
    }

    if(priorityItems.find(priority) == priorityItems.end()){
//        vector<string> keys = {key};
//        priorityItems[priority] = keys;
    } else {
        priorityItems[priority].push_back(key);
    }
}

PriorityExpiryCache::Item* PriorityExpiryCache::Get(string key)
{
    return nullptr;
}

void PriorityExpiryCache::SetMaxItems(int maxItems)
{

}

void PriorityExpiryCache::evictItems(int currentTime)
{

}

void PriorityExpiryCache::remove(string key)
{
    Item* item = items.at(key);
    items.erase(key);
//    auto p = find(priorityItems.begin(), priorityItems.end(), item->priority);
}


int main(int argc, char** argv)
{
  std::cout << "Priority Expiry Queue\n";
}