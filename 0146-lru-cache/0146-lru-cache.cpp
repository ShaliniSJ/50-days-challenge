class LRUCache {
public:
    list<pair<int,int>>ls;
    unordered_map<int,list<pair<int,int>>::iterator>mp;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())return -1;
        ls.splice(ls.begin(),ls,mp[key]);
        return ls.front().second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            ls.splice(ls.begin(),ls,mp[key]);
            ls.front().second = value;
            // mp[key] = ls.begin();
        }
        else{
            if(cap == mp.size()){
                mp.erase(ls.back().first);
                ls.pop_back();
                // ls.push_front({key,value});
            }
            ls.push_front({key,value});
            mp[key] = ls.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */