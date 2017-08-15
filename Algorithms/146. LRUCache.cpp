/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:
LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        if (cacheMap_.find(key) != cacheMap_.end()) {
            auto it = cacheMap_[key];
            if (it != cacheList_.begin())
                cacheList_.splice(cacheList_.begin(), cacheList_, it);
            return it->value_;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cacheMap_.find(key) != cacheMap_.end()) {
            auto it = cacheMap_[key];
            if (it != cacheList_.begin())
                cacheList_.splice(cacheList_.begin(), cacheList_, it);
            it->value_ = value;
        }
        else {
            if (cacheMap_.size() == capacity_) {
                cacheMap_.erase(cacheList_.back().key_);
                cacheList_.pop_back();
            }
            cacheList_.push_front(CacheNode(key, value));
            cacheMap_[key] = cacheList_.begin();
        }
    }

private:
    struct CacheNode {
        int key_;
        int value_;
        CacheNode(int key, int value) : key_(key), value_(value) {}
    };

    std::size_t capacity_;
    std::list<CacheNode> cacheList_;
    std::unordered_map<int, std::list<CacheNode>::iterator> cacheMap_;

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
