class Node {
public:
    int key;
    int data;
    Node* prev;
    Node* next;

    Node(int key, int val, Node* prev, Node* next) {
        this->key = key;
        this->data = val;
        this->prev = prev;
        this->next = next;
    }
};

class LRUCache {
public:
    int cap;
    int currentNodes = 0;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        this->cap = capacity;
        head = new Node(0, 0, nullptr, nullptr);
        tail = new Node(0, 0, head, nullptr);
        head->next = tail;
    }

    void moveToFront(Node* node) {
        // Remove node from current position
        node->prev->next = node->next;
        node->next->prev = node->prev;

        // Insert right after head
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (mp.count(key)) {
            Node* node = mp[key];
            moveToFront(node);
            return node->data;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            Node* node = mp[key];
            node->data = value;
            moveToFront(node);
        } else {
            if (currentNodes == cap) {
                Node* lru = tail->prev;
                lru->prev->next = tail;
                tail->prev = lru->prev;
                mp.erase(lru->key);
                delete lru;
                currentNodes--;
            }

            Node* newNode = new Node(key, value, head, head->next);
            head->next->prev = newNode;
            head->next = newNode;
            mp[key] = newNode;
            currentNodes++;
        }
    }
};
