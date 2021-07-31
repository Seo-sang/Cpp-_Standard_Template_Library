#include <iostream>

using namespace std;

template <typename T>
class mylist{
private:
    struct node {
        T data;
        node* prev;
        node* next;

        node(T input) {
            data = input;
            prev = NULL;
            next = NULL;
        }

        node() {
            data = 0;
            prev = NULL;
            next = NULL;
        }
    };
public:
    node* head;
    node* tail;
    node* fin;
    int num;

    class myiterator {
        node* current;
    public:
        myiterator(node* node = 0) : current(node) {};

        myiterator& operator++() {
            current = current->next;
            return *this;
        }
        
        myiterator& operator--() {
            current = current->prev;
            return *this;
        }

        node* operator&() {
            return current;
        }

        T& operator*() {
            return current->data;
        }

        bool operator !=(const myiterator& cmp) {
            return (current != cmp.current);
        }

        bool operator ==(const myiterator& cmp) {
            return (current == cmp.current);
        }
    };

    mylist() {
        num = 0;
        head = NULL;
        tail = NULL;
        fin = new node(); //list의 마지막을 의미 (head와 연결)
    }
    

    int size() {
        return num;
    }
    
    bool empty() {
        if(num) return false;
        else return true;
    }

    T front() {
        return head->data;
    }

    T back() {
        return tail->data;
    }

    void push_back(T input) {
        if(num == 0) {
            head = new node(input);
            tail = head;
            head->next = fin;
            head->prev = fin;
            fin->prev = head;
            fin->next = head;
        }
        else {
            tail->next = new node(input);
            tail->next->prev = tail;
            tail = tail->next;
            tail->next = fin;
            fin->prev = tail;
        }
        num++;
    }

    void pop_back() {
        if(num == 1) {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else {
            node* before = tail->prev;
            before->next = fin;
            fin->prev = before;
            delete tail;
            tail = before;
        }
        num--;
    }

    void push_front(T input) {
        if(num == 0) {
            head = new node(input);
            tail = head;
            head->next = fin;
            head->prev = fin;
            fin->prev = head;
            fin->next = head;
        }
        else {
            head->prev = new node(input);
            head->prev->next = head;
            head = head->prev;
            head->prev = fin;
            fin->next = head;
        }
        num++;
    }

    void pop_front() {
        if(num == 1) {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else {
            node* nxt = head->next;
            delete head;
            head = nxt;
            head->prev = fin;
            fin->next = head;
        }
        num--;
    }

    void insert(myiterator pos, T input) {
        node* now = &pos;
        node* prevnode = now->prev;
        node* newnode = new node(input);
        prevnode->next = newnode;
        newnode->prev = prevnode;
        newnode->next = now;
        now->prev= newnode;
        if(now == head) head = newnode;
        if(now == end) tail = newnode;
        num++;
    }

    myiterator erase(myiterator pos) {
        node* now = &pos;
        node* prevnode = now->prev;
        node* nextnode = now->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
        if(now == head) nextnode = head;
        if(now == tail) prevnode = tail;
        delete now;

        return myiterator(nextnode);
    }

    myiterator begin() {
        return myiterator(head);
    }
    
    myiterator end() {
        return myiterator(fin);
    }
};


int main() {
    mylist<int> list;

    for(int i = 1; i <= 10; i++)
        list.push_back(i);

    for(auto ite = list.begin(); ite != list.end(); ++ite) 
        cout << *ite << ' ';

    cout << endl;

    for(int i = 0; i < 3; i++) 
        list.pop_back();
    

    for(auto ite = list.begin(); ite != list.end(); ++ite) 
        cout << *ite << ' ';
    
    cout << endl;

    for(int i = 0; i < 3; i++) 
        list.push_front(i + 100);
    
    for(auto ite = list.begin(); ite != list.end(); ++ite) 
        cout << *ite << ' ';
    
    cout << endl;
    
    for(int i = 0; i < 6; i++) 
        list.pop_front();
        
    for(auto ite = list.begin(); ite != list.end(); ++ite) 
        cout << *ite << ' ';
}