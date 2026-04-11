class Node {
    public:
        int val;
        Node* next;
        Node(int val) : val(val), next(nullptr) {}
        Node(int val, Node* next) : val(val), next(next) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = new Node(-1);
        tail = head;
    }

    int get(int index) {
        Node* curr = head->next;
        int i = 0;
        while (curr != nullptr) {
            if (i==index) {
                return curr->val;
            }
            i++;
            curr = curr->next;
        }
        return -1;
    }

    void insertHead(int val) {
        Node* temp = new Node(val);
        temp->next = head->next;
        head->next = temp;
        if (temp->next == nullptr) {
            tail = temp;
        }
    }
    
    void insertTail(int val) {
        Node* temp = new Node(val);
        tail->next = temp;
        tail = temp;
    }

    bool remove(int index) {
        Node* curr = head->next;
        Node* prev = head;
        while (curr!=nullptr) {
            if (index==0) {
                prev->next = curr->next;
                if (curr==tail) {
                    tail = prev;
                }
                delete curr;
                return true;
            }
            index--;
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> res;
        Node* curr = head->next;
        while (curr!=nullptr) {
            res.push_back(curr->val);
            curr = curr->next;
        }
        return res;
    }
};
