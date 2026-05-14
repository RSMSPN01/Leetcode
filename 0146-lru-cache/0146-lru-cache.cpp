// I am thinking to use satck over here bcs the put operation and the evict
// operation will take constant time but the get operation, how to make that
// constant time i don't have any idea about that

// Or i was thinking to create a stack of type map that will also do the job but
// handling it is difficult and also the worst T.C = O(n)

// Lets seek some help and see how we have to do this
// So we are storing the key as integer value but the value pair as a node
// itself to update the value quickly
class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key = -1, int val = -1) {
        this->val = val;
        this->key = key;
        prev = nullptr;
        next = nullptr;
    }
    // create three helping functions
    void insertAftrHead(Node* head, Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }
    void deleteNode(Node* node) {
        // this will not free the whole memory for the node but just change some
        // pointer address, this will save memory time to create a new node
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        node->prev = nullptr;
        node->next = nullptr;
    }
    void deleteBfrTail(Node* tail) {
        Node* prevNode = tail->prev;
        Node* thirdLastNode = prevNode->prev;
        thirdLastNode->next = tail;
        tail->prev = thirdLastNode;
        prevNode->next = nullptr;
        prevNode->prev = nullptr;
    }
};
class LRUCache : public Node {
public:
    unordered_map<int, Node*> cache; // store the address
    Node* head = new Node();         // two reference nodes are created now
    Node* tail = new Node();
    int capacity = 0;
    LRUCache(int capacity) {
        // capacity size map is created, already a public member
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            // key is present in the cache do two things
            // get the value and move the key and pair to front
            Node* pairNode = cache[key];
            deleteNode(pairNode);
            insertAftrHead(head, pairNode);
            return pairNode->val;
        }
        return -1;
    }

    void put(int key, int value) {
        // three cases are there
        if (cache.size() == capacity) {
            // case 1: size is already full
            if(cache.find(key) != cache.end()){
                // size if full but key is already there so just update
                Node* pairNode = cache[key];    
                deleteNode(pairNode);           
                pairNode->val = value;          
                insertAftrHead(head, pairNode); 
                cache[key] = pairNode;
            }else{
            Node* prevNode = tail->prev;          // get the node first
            cache.erase(prevNode->key);           // delete the data from map
            deleteBfrTail(tail);                  // delete least used value
            Node* newNode = new Node(key, value); // create a new node
            insertAftrHead(head, newNode);        // insert in LL
            cache[key] = newNode;                 // update the map too
            }
        } else {
            // case 2: Key is not present
            if (cache.find(key) == cache.end()) {
                Node* newNode = new Node(key, value);
                insertAftrHead(head, newNode);
                cache[key] = newNode;
            } else {
                // Case 3: key is already present, just update the val
                Node* pairNode = cache[key];    // get the pair node
                deleteNode(pairNode);           // delete from current place
                pairNode->val = value;          // update the new value
                insertAftrHead(head, pairNode); // update the position to first
                cache[key] = pairNode;          // update the map again
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */