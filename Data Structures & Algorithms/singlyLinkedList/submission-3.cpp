struct Node{
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class LinkedList {
private:
    Node* dummy;
    Node* tail;
    int size;

public:
    LinkedList() {
        dummy = new Node(0);
        tail = dummy;
        size=0;
    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;
        else {
            Node* curr = dummy->next;
            for (int i = 0 ; i < index ; i++) {
                curr = curr->next;
            }
            return curr->val;
        }
    }

    void insertHead(int val) {
        Node* head = new Node(val);
        head -> next = dummy -> next;
        dummy -> next = head;
        if (size == 0) {
            tail = head;
        }
        size++;
    }
    
    void insertTail(int val) {
        Node* newtail = new Node(val);
        tail -> next = newtail;
        tail =  newtail;
        size++;
    }

    bool remove(int index) {
        if (index < 0 || index >= size)
            return false;
        else {
            Node* prev = dummy;
            for (int i = 0; i < index; ++i) {
            prev = prev->next;
        }
        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        if (index == size - 1) {
            tail = prev;
        }
        delete toDelete; // 釋放記憶體
        size--;
        return true;
        }
    }

    vector<int> getValues() {
        vector<int> vals;
        Node* curr = dummy -> next;
        while (curr != nullptr){
            vals.push_back(curr->val);
            curr = curr->next;
        }
        return vals;
    }
};
