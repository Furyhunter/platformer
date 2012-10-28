#include "LinkedList.h"

template <class T>
class LinkedListNode {
public:
    LinkedListNode() {
        next = 0;
        prev = 0;
    }

    LinkedListNode(LinkedListNode* prev, T* item, LinkedListNode* next) {
        this->next = next;
        this->prev = prev;
        data = item;
    }

    LinkedListNode* next;
    LinkedListNode* prev;
    T* data;
};

template <class T>
LinkedList<T>::LinkedList() {
    last = 0;
    first = 0;
    size = 0;
}

template <class T>
void LinkedList<T>::add(T& item) {
    LinkedListNode<T>* node = new LinkedListNode<T>(last, item, 0);

    if (first == 0) {
        first = node;
        last = node;
    } else {
        last->next = node;
        node->prev = last;
        last = node;
    }

    size += 1;
}

template <class T>
void LinkedList<T>::add(int index, T& item) {
    int count = 0;
    LinkedListNode<T>* itr = first;
    LinkedListNode<T>* node = new LinkedListNode<T>(0, item, 0);

    if (size == 0 && index = 0) {
        add(item);
        delete node;
        return;
    }

    if (size == 0 && index != 0) {
        delete node;
        return;
    }

    if (index == 0) {
        first->prev = node;
        node->next = first;
        first = node;
        size += 1;
        return;
    }

    if (index == size - 1) {
        last->next = node;
        node->prev = last;
        last = node;
        size += 1;
        return;
    }


    while (itr != 0 && count <= index) {
        if (count == index) {
            node->prev = itr->prev;
            node->next = itr;
            itr->prev = node;
            size += 1;
            return;
        }
        count += 1;
        itr = itr->next;
    }
}

template <class T>
void LinkedList<T>::set(int index, T& item) {
    int count = 0;
    LinkedListNode<T>* itr = first;
    LinkedListNode<T>* node = new LinkedListNode<T>(0, item, 0);

    if (size == 0 && index == 0) {
        add(item);
        delete node;
        return;
    }

    if (index == 0) {
        first->prev = node;
        node->next = first;
        first = node;
        return;
    }

    if (index == size - 1) {
        last->next = node;
        node->prev = last;
        last = node;
        return;
    }

    while (itr != 0) {
        if (count == index) {
            itr->prev->next = node;
            itr->next->prev = node;
            delete itr;
            return;
        }
        count++;
        itr = itr->next;
    }
}

template <class T>
void LinkedList<T>::remove(T& item) {
    LinkedListNode<T>* itr = first;

    if (size == 0) {
        return;
    }

    while (itr != 0) {
        if (itr->data == &item) {
            itr->next->prev = itr->prev;
            itr->prev->next = itr->next;
            size -= 1;
            delete itr;
            return;
        }
        itr = itr->next;
    }
}

template <class T>
void LinkedList<T>::remove(int index) {
    int count = 0;
    LinkedListNode<T>* itr = first;

    if (size == 0) {
        return;
    }

    if (index == 0) {
        first->next->prev = 0;
        first = first->next;
        size -= 1;
        return;
    }

    if (index == size - 1) {
        last->prev->next = 0;
        last = last->prev;
        size -= 1;
        return;
    }

    while (itr != 0) {
        if (count == index) {
            itr->next->prev = itr->prev;
            itr->prev->next = itr->next;
            size -= 1;
            delete itr;
            return;
        }
        count++;
        itr = itr->next;
    }
}
