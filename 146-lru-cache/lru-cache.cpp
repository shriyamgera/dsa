class LRUCache {
public:
    int capacity;
    list<pair<int, int>> lruList; // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> cache;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        // Move accessed item to front (most recently used)
        lruList.splice(lruList.begin(), lruList, cache[key]);
        return cache[key]->second;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key exists: update and move to front
            cache[key]->second = value;
            lruList.splice(lruList.begin(), lruList, cache[key]);
        } else {
            // New key
            if (lruList.size() == capacity) {
                // Remove least recently used (last item)
                int lruKey = lruList.back().first;
                lruList.pop_back();
                cache.erase(lruKey);
            }
            lruList.push_front({key, value});
            cache[key] = lruList.begin();
        }
    }
};
