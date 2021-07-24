#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

template <typename T>
class myvector{
private:
    int num;
    int len;
    T* tmp;
    T* head;
    T* tail;
public:
    T* arr;
public:
    class myiterator {
        T* current;
    public:
        myiterator(T* node = 0) : current(node) {};

        myiterator& operator++() {
            current++;
            return *this;
        }
        
        myiterator& operator--() {
            current--;
            return *this;
        }

        T& operator*() {
            return *current;
        }

        bool operator !=(const myiterator& cmp) {
            return (current != cmp.current);
        }
    };

    myvector() {
        myvector::num = 0;
        myvector::arr = (T*)malloc(sizeof(T) * 10);
        memset(arr, 0, sizeof(arr));
        len = 10;
        memset(arr, 0, sizeof(arr));
        head = NULL;
        tail = NULL;
    }

    T front() {
        return *head;
    }

    T back() {
        return arr[num-1];
    }

    int size() {
        return num;
    }

    bool empty() {
        if(num) return false;
        else return true;
    }

    void clear() {
        num = 0;
        free(arr);
        arr = (T*)malloc(sizeof(T) * 10);
        memset(arr, 0, sizeof(arr));
    }

    void push_back(T input) {
        if(num == 0) {
            head = &arr[0];
        }
        if(num == len-1) {
            len *= 2;
            tmp = arr;
            arr = (T*)malloc(sizeof(T) * len);
            for(int i = 0; i < num ; i++) arr[i] = tmp[i];
            free(tmp);
            head = &arr[0];
        }
        arr[num++] = input;
        tail = &arr[num];
    }

    void pop_back() {
        arr[num--] = 0;
        if(num < len/2) {
            len /= 2;
            tmp = arr;
            arr = (T*)malloc(sizeof(T) * len);
            for(int i = 0; i < num; i++) arr[i] = tmp[i];
            free(tmp);
            head = &arr[0];
        }
        tail = &arr[num];
        if(num == 0) {
            head = NULL;
            tail = NULL;
        }
    }

    void resize(int n) {
        num = n;
        int tmplen;
        for(int tmplen = 10; tmplen <= n; tmplen *= 2);
        tmp = arr;
        arr = (T*)malloc(sizeof(T) * tmplen);
        if(tmplen < num) for(int i = 0; i < tmplen; i++) arr[i] = tmp[i];
        else for(int i = 0; i < num; i++) arr[i] = tmp[i];
        free(tmp);
        head = &arr[0];
        tail = &arr[num];   
    }

    T at(T i) {
        return arr[i];
    }

    myiterator begin() {
        return myiterator(head);
    }

    myiterator end() {
        return myiterator(tail);
    }
};
