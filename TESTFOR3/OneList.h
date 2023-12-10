#pragma once
#include <iostream>

using namespace std;


template <class T>
struct Element {
    
    T data;
    Element* next;
};


template <typename T>
class OneList {
private:

    Element<T>* begin;
    Element<T>* end;
    unsigned long int count;
    unsigned long int pos;
    Element<T>* move(int index)
    {
        if (count > 0)
        {
            Element<T>* t = begin;
            for (int i = 0; i < index; i++)
                t = t->next;
            return t;
        }
        return nullptr;
    }
    void add(T _data)
    {
        Element<T>* elem = new Element<T>;
        elem->data = _data;
        elem->next = nullptr;

        if (begin == nullptr)
        {
            begin = end = elem;
        }
        else
        {
            end->next = elem;
            end = elem;
        }

        count++;
    }
    void del(int index)
    {
        if (count == 0)
            return;

        if ((index < 0) || (index >= count))
            return;

        if (index == 0)
        {
            Element<T>* t = begin;
            begin = begin->next;
            delete t;

            if (count == 1) {
                end = nullptr;
            }
        }
        else
        {
            Element<T>* t = move(index - 1);
            Element<T>* t2 = t->next;

            t->next = t2->next;
            delete t2;

            if (index == count - 1) {
                end = t;
            }
        }

        count--;
    }
    void copy(const OneList& obj)
    {
        clear();

        Element<T>* t = obj.begin;

        for (int i = 0; i < obj.count; i++)
        {
            add(t->data);
            t = t->next;
        }

        count = obj.count;
    }

public:
    OneList()
    {
        begin = end = nullptr;
        count = 0;
        pos = 0;
    }
    OneList(const OneList& obj)
    {
        copy(obj);
    }
    ~OneList() {
        clear();
    }
    void push_front(T data) {
        insert(0, data);
    }
    void push_back(T _data) {
        add(_data);
    }
    void insert(int index, T item)
    {
        if ((count != 0) && ((index < 0) || (index >= count)))
            return;

        Element<T>* t = move(index);

        if (t == nullptr)
        {
            add(item);
        }
        else
        {
            Element<T>* t2 = new Element<T>;
            t2->data = item;

            if (index == 0)
            {
                t2->next = begin;
                begin = t2;
            }
            else
            {
                t = move(index - 1);
                t2->next = t->next;
                t->next = t2;
            }

            count++;
        }
    }
    void pop_front() {
        del(0);
    }
    void pop_back() {
        del(count - 1);
    }
    void remove(T data) {
        if (count == 0)
            return;

        Element<T>* current = begin;
        Element<T>* previous = nullptr;

        while (current != nullptr) {
            if (current->data == data) {
                if (previous == nullptr) {
                    begin = current->next;
                    delete current;
                    current = begin;
                }
                else {
                    previous->next = current->next;
                    delete current;
                    current = previous->next;
                }
                count--;
            }
            else {
                previous = current;
                current = current->next;
            }
        }
        if (count == 0) {
            end = nullptr;
        }
        else if (previous != nullptr && previous->next == nullptr) {
            end = previous;
        }
    }
    void clear()
    {
        while (begin != nullptr)
            del(0);
    }
    T front() {
        if (begin == nullptr)
            throw "The list is empty";

        return begin->data;
    };
    T back() {
        if (begin == nullptr)
            throw "The list is empty";

        return end->data;
    };
    int size() {
        return count;
    }
    T& operator[](int index)
    {
        if ((index < 0) || (index > count - 1))
            throw out_of_range("Incorrect index");

        Element<T>* t = move(index);
        return t->data;
    }

    T operator++() {
        if (this->pos < this->count) {
            this->pos++;
        }

        return move(pos)->data;
    };

    T operator++(int) {
        if (this->pos < this->count) {
            this->pos++;
        }

        return move(pos)->data;
    };

    T operator--() {
        if (pos > 0) {
            pos--;
        }

        return move(pos)->data;
    }
};