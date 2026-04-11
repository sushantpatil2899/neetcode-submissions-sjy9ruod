class Element {
    public:
    int val;
    Element* next;
    Element* prev;
    Element(int val): val(val), next(nullptr), prev(nullptr) {}
};

class Deque {
private:
    Element* head;
    Element* tail;
public:
    Deque() {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty() {
        if (head==nullptr) {
            return true;
        }
        return false;
    }

    void append(int value) {
        Element* temp = new Element(value);
        if (tail==nullptr) {
            head = temp;
            tail = head;
        }
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

    void appendleft(int value) {
        Element* temp = new Element(value);
        if (head==nullptr) {
            head = temp;
            tail = head;
        }
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    int pop() {
        int value;
        if (tail==nullptr) {
            value = -1;
        }
        else if (head==tail) {
            value = tail->val;
            head = nullptr;
            tail = nullptr;
        }
        else {
            value = tail->val;
            tail->prev->next = nullptr;
            tail =  tail->prev;
        }
        return value;
    }

    int popleft() {
        int value;
        if (head==nullptr) {
            value = -1;
        }
        else if (head==tail) {
            value = head->val;
            head = nullptr;
            tail = nullptr;
        }
        else {
            value = head->val;
            head->next->prev = nullptr;
            head =  head->next;
        }
        return value;
    }
};
