#pragma once

template <class T>
class List {
public:
    virtual void add(T& item) = 0;
    virtual void add(int index, T& item) = 0;
    virtual void set(int index, T& item) = 0;
    virtual void remove(T& item) = 0;
    virtual void remove(int index) = 0;
    virtual int getSize() = 0;
};