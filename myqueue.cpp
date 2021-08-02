#include <iostream>

using namespace std;

template <typename T>
class myqueue {
private:
    struct node {
        T data;
        node* next;

        node(T input) {
            data = input;
            next = NULL;
        }

        node() {
            data = 0;
            next = NULL;
        }
    };
    
public:
    node* head;
    node* tail;
    int num;

    myqueue() {
        num = 0;
        head = NULL;
        tail = NULL;
    }

    bool empty() {
        if(num) return false;
        else return true;
    }

    int size() {
        return num;
    }

    T front() {
        return head->data;
    }

    T back() {
        return tail->data;
    }

    void push(T input) {
        if(num == 0) {
            head = new node(input);
            tail = head;
        }
        else {
            tail->next = new node(input);
            tail = tail->next;
        }
        num++;
    }

    void pop() {
        if(num == 1) {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else {
            node* del = head;
            head = head->next;
            delete del;
        }
        num--;
    }
};

int main() {
    myqueue<int> q;
    for(int i = 1; i <= 10; i++) {
        q.push(i);
    }
    while(!q.empty()) {
        cout << q.front() << endl; q.pop();
    }
}