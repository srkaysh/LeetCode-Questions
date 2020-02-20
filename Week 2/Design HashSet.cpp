#include <vector>
#include <forward_list>

using namespace std;

class MyHashSet {
private:
    vector<forward_list<int>> hashSet;
    int size;
    
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        size = 1000;
        hashSet.resize(size);
    }
    
    void add(int key) {
        auto &list = hashSet[key%size];
        if(list.empty()) list.insert_after(list.before_begin(), key);
        for(auto it = list.begin(); it != list.end();it++){
            if(*it == key) return;
        }
        list.emplace_front(key);
    }
    
    void remove(int key) {
        auto &list = hashSet[key%size];
        if(list.empty()) return;
        auto prev_it = list.before_begin();
        for(auto it = list.begin(); it != list.end();it++){
            if(*it == key){
                list.erase_after(prev_it);
                return;
            }
            prev_it = it;
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto &list = hashSet[key%size];
        if(list.empty()) return false;
        for(auto it = list.begin(); it != list.end();it++){
            if(*it == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
