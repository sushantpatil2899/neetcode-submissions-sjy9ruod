class CacheNode {
    public:
        int key, val;
        CacheNode* next;
        CacheNode* prev;
        CacheNode(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
};

class LRUCache {
    private:
        int capacity;
        unordered_map<int, CacheNode*> mp;
        CacheNode* head;
        CacheNode* tail;

        void removeNode(CacheNode* node) {
            if (!node) return;
            if (node->prev) node->prev->next = node->next;
            else head = node->next;

            if (node->next) node->next->prev = node->prev;
            else tail = node->prev;
        }

        void addToTail(CacheNode* node) {
            node->next = nullptr;
            node->prev = tail;
            if (tail) tail->next=node;
            tail = node;
            if (!head) head=node;
        }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        CacheNode* temp = mp[key];
        removeNode(temp);
        addToTail(temp);
        return temp->val;
    }
    
    void put(int key, int value) {
        if (mp.find(key)!=mp.end()) {
            CacheNode* temp = mp[key];
            temp->val = value;
            removeNode(temp);
            addToTail(temp);
        }
        else {
            if (mp.size()==capacity) {
                mp.erase(head->key);
                removeNode(head);
            }
            CacheNode* temp = new CacheNode(key, value);
            addToTail(temp);
            mp[key] = temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */