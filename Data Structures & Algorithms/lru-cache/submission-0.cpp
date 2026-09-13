struct DLL{
    int key;
    int val;
    DLL* next;
    DLL* prev;
    DLL(int k, int v){
        key = k;
        val = v;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, DLL*> mp;
    DLL* head;
    DLL* tail;
    int size;
    LRUCache(int capacity) {
        size = capacity;
        head = new DLL(0, 0);
        tail = new DLL(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    void removeLRU(DLL* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addMRU(DLL* node){
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }
    
    int get(int key) {
        if (!mp.count(key)) return -1;

        DLL* mru = mp[key];
        removeLRU(mru);
        addMRU(mru);
        return mru->val;
    }
    
    void put(int key, int value) {
        if (mp.count(key)){
            DLL* mru = mp[key];
            mru->val = value;
            removeLRU(mru);
            addMRU(mru);
        }
        else{
            if (mp.size() == size){
                DLL* lru = tail->prev;
                removeLRU(lru);
                mp.erase(lru->key);
                delete lru;
            }
            DLL* mru = new DLL(key, value);
            mp[key] = mru;
            addMRU(mru);
        }
    }
};
