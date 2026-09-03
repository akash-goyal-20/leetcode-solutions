class MyHashSet {
public:
    vector<list<int>> buckets;
    int size;
    MyHashSet() {
        size = 1e4;
        buckets.resize(1e4);
    }

    void add(int key) {
        int hashkey = key % size;
        auto& bucket = buckets[hashkey];

        for (auto& it : bucket) {
            if (it == key) {
                return;
            }
        }
        bucket.push_back(key);
    }

    void remove(int key) {
        int hashkey = key % size;
        auto& bucket = buckets[hashkey];

        for (auto& it : bucket) {
            if (it == key) {
                bucket.remove(it);
                return;
            }
        }
    }

    bool contains(int key) {
        int hashkey = key % size;
        auto& bucket = buckets[hashkey];

        for (auto& it : bucket) {
            if (it == key) {
                return true;
            }
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