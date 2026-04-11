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
    int size;
public:
    Deque() {
        head = nullptr;
        tail = nullptr;
        size = 0;
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
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void appendleft(int value) {
        Element* temp = new Element(value);
        if (head==nullptr) {
            head = temp;
            tail = head;
        }
        else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
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
        size--;
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
        size--;
        return value;
    }

    int queuesize() {
        return size;
    }
};

class MyStack {
private:
Deque q1;
Deque q2;
public:
    MyStack() {
    }
    
    void push(int x) {
        q1.append(x);
    }
    
    int pop() {
        int size = q1.queuesize();
        for (int i=0;i<size-1;i++) {
            q2.append(q1.popleft());
        }
        int ret = q1.popleft();
        size = q2.queuesize();
        for (int i=0;i<size;i++) {
            q1.append(q2.popleft());
        }
        return ret;
    }
    
    int top() {
        int size = q1.queuesize();
        for (int i=0;i<size-1;i++) {
            q2.append(q1.popleft());
        }
        int ret = q1.popleft();
        size = q2.queuesize();
        for (int i=0;i<size;i++) {
            q1.append(q2.popleft());
        }
        q1.append(ret);
        return ret;
    }
    
    bool empty() {
        return q1.isEmpty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */