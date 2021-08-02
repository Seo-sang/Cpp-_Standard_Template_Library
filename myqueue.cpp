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

    void swap(myqueue<T> &with) {
        myqueue<T> tmp = *this;
        *this = with;
        with = tmp;
    }
};

int main() {
    myqueue<int> q1, q2;
    for(int i = 1; i <= 10; i++) 
        q1.push(i);
    
    for(int i = 101; i <= 110; i++)
        q2.push(i);

    q1.swap(q2);

    while(!q1.empty()) {
        cout << q1.front() << ' ';
        q1.pop();
    }
    
    cout << endl;

    while(!q2.empty()) {
        cout << q2.front() << ' ';
        q2.pop();
    }
    
}