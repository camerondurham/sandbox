#include<vector>
#include<queue>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<unordered_map>
#include<algorithm>

using namespace std;


class PriorityExpiryCache
{

public:
    PriorityExpiryCache(){}
    PriorityExpiryCache(int capacity);
    ~PriorityExpiryCache();
    struct Item {
        string data;
        int priority;
        int expireTime;
        Item(string data, int priority, int expireTime) :
                data(data),
                priority(priority),
                expireTime(expireTime)
        { }

    };

    void setItem(string key, string value, int priority, int expireTime);
    Item* getItem(string key);
    void evictItems(int currentTime);

private:
    int capacity;
    unordered_map<string, PriorityExpiryCache::Item*> items;
    map<int, vector<string>> expireItems;
    unordered_map<int, vector<string>> priorityItems;
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

void PriorityExpiryCache::setItem(string key, string value, int priority, int expireTime)
{
    if(items.find(key) != items.end()) {
        remove(key);
    }
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

PriorityExpiryCache::Item* PriorityExpiryCache::getItem(string key)
{
    return nullptr;
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
  cout << "Priority Expiry Queue\n";
}