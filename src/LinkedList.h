#pragma once

#include "List.h"

template <class T>
class LinkedListNode;

template <class T>
class LinkedList : public List<T> {
public:
    LinkedList();

    virtual void add(T& item);
    virtual void add(int index, T& item);
    virtual void set(int index, T& item);
    virtual void remove(T& item);
    virtual void remove(int index);

    virtual int getSize() {
        return size;
    }
private:
    LinkedListNode<T>* first;
    LinkedListNode<T>* last;
    int size;
};
