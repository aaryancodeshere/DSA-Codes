class LRUCache {
public:
    unordered_map<int,pair<list<int>::iterator,int>> mp;
    int cap;
    list<int> dll;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.contains(key)){
            dll.erase(mp[key].first);
            dll.push_front(key);
            mp[key].first = dll.begin();
            return mp[key].second;
        }
        else{
            return -1;
        }
        
    }
    
    void put(int key, int value) {
        if(mp.contains(key)){
            mp[key].second = value;
            dll.erase(mp[key].first);
            dll.push_front(key);
            mp[key].first = dll.begin();
        }
        else{
            dll.push_front(key);
            mp[key]={dll.begin(),value};
        }
        if(mp.size()>cap){
            int del = dll.back();
            mp.erase(del);
            dll.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */