#include <vector>
#include <forward_list>

using namespace std;

class MyHashMap {
private:    
    vector<forward_list<pair<int,int>>> hashMap;
    size_t keySize; 
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        keySize = 65537;
        hashMap.resize(keySize);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto &list = hashMap[key%keySize];
        int index = key/keySize;
        
        if(list.empty()) list.emplace_front(index, value);
        else{
            auto prev_it = list.before_begin();
            auto it = prev_it;
            for(it++; it != list.end(); it++){
                if(it->first >= index) break;
                prev_it = it;
            }
            if(it != list.end() && it->first == index) it->second = value;
            else list.emplace_after(prev_it, index, value);
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = key/keySize;
        const auto &list = hashMap[key%keySize];
        
        if(list.empty()) return -1;
        for(auto it = list.begin(); it != list.end(); it++){
            if(it->first == index) return it->second;
            else if(it->first > index) return -1;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto &list = hashMap[key%keySize];
        int index = key/keySize;
        
        if(list.empty()) return;
        else{
            auto prev_it = list.before_begin();
            auto it = prev_it;
            for(it++; it != list.end(); it++){
                if(it->first >= index) break;
                prev_it = it;
            }
            if(it != list.end() && it->first == index) it = list.erase_after(prev_it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
