class Node {
   public:
    int data;
    Node* next;

    Node(int val) {
        this->data = val;
        this->next = nullptr;
    }
};

class MyHashSet {
   private:
    Node* head;

   public:
    MyHashSet() { head = nullptr; }

    void add(int key) {
        Node* temp = head;

        if (contains(key)) {
            return;
        }

        Node* newNode = new Node(key);

        newNode->next = head;
        head = newNode;
    }

    void remove(int key) {
        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (temp->data == key) {
                if (prev == nullptr) {
                    head = head->next;
                } else {
                    prev->next = temp->next;
                }

                delete temp;
                return;
            }

            prev = temp;
            temp = temp->next;
        }
    }

    bool contains(int key) {
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->data == key) {
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    // Free all remaining nodes
    ~MyHashSet() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;

            delete temp;
        }
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */