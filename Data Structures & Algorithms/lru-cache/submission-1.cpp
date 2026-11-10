
class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v)
            : key(k), value(v),
              prev(nullptr), next(nullptr) {}
    };

    int capacity;
    int count;

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;



public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        count = 0;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        auto it = mp.find(key);
        if (it  == mp.end()){
            return -1;
        }
        else{
            Node* node = it->second;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->next = tail;
            tail->prev->next = node;
            node->prev = tail->prev;
            tail->prev = node;
            return node->value;
        }
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);

        if (it != mp.end()) {
            Node* node = it->second;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->next = tail;
            tail->prev->next = node;
            node->prev = tail->prev;
            tail->prev = node;
            node->value = value;
            return;
        }
        else if (count < capacity){
            Node* node = new Node(key, value);
            node->next = tail;
            tail->prev->next = node;
            node->prev = tail->prev;
            tail->prev = node;
            mp[key] = node;
            count++;
        }
        else{
            Node* node = new Node(key, value);
            Node* deleted = head->next;
            head->next->next->prev = head;
            head->next = head->next->next;
            node->next = tail;
            tail->prev->next = node;
            node->prev = tail->prev;
            tail->prev = node;
            mp[key] = node;
            mp.erase(deleted->key);
        }
    }
};
