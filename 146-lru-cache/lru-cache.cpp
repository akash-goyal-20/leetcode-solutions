class LRUCache {
    class Node {

    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    void addNode(Node* node) {
        Node* temp = head->next;

        head->next = node;
        node->prev = head;

        node->next = temp;
        temp->prev = node;
    }

    void deleteNode(Node* node) {
        Node* nodePrev = node->prev;
        Node* nodeNext = node->next;

        nodePrev->next = nodeNext;
        nodeNext->prev = nodePrev;
    }

    int cap;
    unordered_map<int, Node*> mp;

public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            int value = node->val;
            deleteNode(node);
            addNode(node);
            return value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* existingNode = mp[key];
            existingNode->val = value;
            deleteNode(existingNode);
            addNode(existingNode);
        } else {
            if (mp.size() == cap) {
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
            }
            Node* newNode = new Node(key, value);
            addNode(newNode);
            mp[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */