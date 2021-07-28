#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

template <typename T>
class mystack {
private:
    int num;
    int len;
    T* tmp;
    T* arr;
public:
    mystack() {
        mystack::num = 0;
        mystack::arr = (T*)malloc(sizeof(T) * 10);
        memset(arr, 0, sizeof(arr));
        len = 10;
        tmp = NULL;
    }

    T top() {
        return arr[num-1];
    }

    int size() {
        return num;
    }

    bool empty() {
        if(num) return false;
        else return true;
    }

    void pop() {
        arr[num--] = 0;
        if(num < len/2) {
            len /= 2;
            tmp = arr;
            arr = (T*)malloc(sizeof(T) * len);
            for(int i = 0; i < num; i++) arr[i] = tmp[i];
            free(tmp);
        }
    }

    void push(T input) {
        if(num == len - 1) {
            len *= 2;
            tmp = arr;
            arr = (T*)malloc(sizeof(T) * len);
            for(int i = 0; i < num; i++) arr[i] = tmp[i];
            free(tmp);
        }
        arr[num++] = input;
    }
};