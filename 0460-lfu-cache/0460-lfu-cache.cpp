// So this is the same problem as the LRU but the problem here is remove the
// least frequency element we need to somehow maintain the frequency so to
// quickly access the lowest frequency

class Node {
    // This is just a simple node for the DLL
public:
    int key;
    int value;
    int freq;
    Node* prev = nullptr;
    Node* next = nullptr;
    Node(int k = -1, int v = -1) {
        key = k;
        value = v;
        freq = 1;
        prev = nullptr;
        next = nullptr;
    }
};
class List {
    // This is DLL implementation
public:
    Node* head;
    Node* tail;
    int size;
    List() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->next = head;
        size = 0;
    }
    // operations to apply on the DLL
    void insertFront(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }

    Node* removeLast() {
        if (size == 0)
            return nullptr;
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }
};
class LFUCache {
private:
    int capacity;
    int minFreq;
    int currentSize;
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
        currentSize = 0;
    }
    // This is where the magic happens
    // understanding this means you get the question
    void updateFrequency(Node* node) {
        int oldFreq = node->freq;
        freqList[oldFreq]->removeNode(node); // node is removed from last freq
        if (oldFreq ==
                minFreq && // if there is no previous freq is left then update
            freqList[oldFreq]->size == 0) {

            minFreq++;
        }
        node->freq++;
        int newFreq = node->freq;
        // create new list if doesn't exist
        if (freqList.find(newFreq) == freqList.end()) {
            freqList[newFreq] = new List();
        }
        // insert into new frequency list
        freqList[newFreq]->insertFront(node);
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) {
            return -1;
        }
        Node* node = keyNode[key]; // particular node is picked
        int val = node->value;
        updateFrequency(node); // update the frequency of the node
        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->value = value;   // update the value with new one
            updateFrequency(node); // update the list
            return;
        }
        if (currentSize == capacity) {
            List* dll = freqList[minFreq];          // whole list is selected
            Node* nodeToRemove = dll->removeLast(); // last node is removed
            keyNode.erase(nodeToRemove->key);       // also remove from the map
            currentSize--;
        }
        Node* newNode = new Node(key, value);
        minFreq = 1;
        // create freq 1 list if absent
        if (freqList.find(1) == freqList.end()) {
            freqList[1] = new List(); // new dll is created here
        }
        freqList[1]->insertFront(newNode); // node is inserted
        keyNode[key] = newNode;            // map is updated too
        currentSize++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */