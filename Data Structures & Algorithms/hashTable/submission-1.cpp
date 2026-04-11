class HashTable {
    private:
        int cap, size;
        vector<pair<int, int>> ht_hash;
public:
    HashTable(int capacity) {
        cap = capacity;
        size = 0;
        ht_hash.resize(cap);
    }

    void insert(int key, int value) {
        int hash_index = key % cap;
        if (ht_hash[hash_index].first == 0) {
            ht_hash[hash_index] = {key, value};
            size++;
        }
        else if (ht_hash[hash_index].first == key) {
            ht_hash[hash_index] = {key, value};
        }
        else {
            hash_index = 0;
            while (hash_index<cap){
                if (ht_hash[hash_index].first == 0) {
                    ht_hash[hash_index] = {key, value};
                    size++;
                    break;
                }
                hash_index++;
            }
        }

        if ((double)size / cap>=0.5) {
            resize();
        }
    }

    int get(int key) {
        int hash_index = key % cap;
        if (ht_hash[hash_index].first == key) {
            return ht_hash[hash_index].second;
        }
        else {
            hash_index = 0;
            while (hash_index<cap){
                if (ht_hash[hash_index].first == key) {
                    return ht_hash[hash_index].second;
                    break;
                }
                hash_index++;
            }
        }
        return -1;
    }

    bool remove(int key) {
        int hash_index = key % cap;
        if (ht_hash[hash_index].first == key) {
            ht_hash[hash_index] = {0,0};
            size--;
            return true;
        }
        else {
            hash_index = 0;
            while (hash_index<cap){
                if (ht_hash[hash_index].first == key) {
                    ht_hash[hash_index] = {0,0};
                    size--;
                    return true;
                }
                hash_index++;
            }
        }
        return false;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return cap;
    }

    void resize() {
        cap = cap * 2;
        ht_hash.resize(cap);
    }
};
