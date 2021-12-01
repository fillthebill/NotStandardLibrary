//
// Created by 原显智 on 2021/12/1.
//

#ifndef UNTITLED_MYVECTOR_H
#define UNTITLED_MYVECTOR_H

#include <iostream>

using namespace std;

// step2 class iterator deleted
// step3
/**
 * 1. define data member as three iterators (pointers), first, last, end_of_vector;
 * 2. intuitively, start with an array of elements T and size of the array.
 *
 *
 * */


template <typename T>
class MyVector {

public:
    typedef T* iterator;

    MyVector(void);
    MyVector(MyVector<T> & from); // copy constructor
    MyVector& operator = (MyVector<T> & from);
    ~MyVector();

    inline int length() {return last-first; }; // 'Redefinition of 'size' as a different kind of symbol '
    void resize();
    void push_back(T element);
    //T& pop_back();

    MyVector::iterator begin();
    MyVector::iterator end();

    //T& operator[](int t) {

    //};

private:
    iterator first;
    iterator last;
    iterator end_of_vector;
    void vector_init(int sz);
};

template <typename T>
void MyVector<T>::vector_init(int sz) {
    first = new T[sz];
    last = first;
    end_of_vector = first+sz;
}


template <typename T>
MyVector<T>::MyVector(void) {
    vector_init(7);
}


template <typename T>
MyVector<T>::MyVector(MyVector<T>& from) {
    int sz = from.size();
    vector_init(sz);
}

template <typename T>
MyVector<T>& MyVector<T>::operator= (MyVector<T>& from) {
    if(this == &from) {
        return *this;
    }else {
        delete[] first; // destruction of element T would be called here;
        vector_init(from.size());
        iterator iterator_to;
        iterator iterator_from = from.begin();
        for(iterator_to = first; iterator_to < end_of_vector; iterator_to++, iterator_from++) {
            *iterator_to = *iterator_from;
        }
        return *this;
    }
}

template <typename T>
MyVector<T>::~MyVector<T>() {
    delete[] first;
}

template <typename T>
void MyVector<T>::resize() {
    iterator old_first = first;
    iterator old_last = last;
    vector_init(2*this->length());

    iterator iterator_from = old_first;
    for(; iterator_from <= old_last; last++, iterator_from++) {
        *last = *iterator_from;

    }
    delete[] old_first;
}

template <typename T>
void MyVector<T>::push_back(T element) {
    if(last == end_of_vector) {
        resize();
        std::cout<< "resize" <<std::endl;
    }
    else {
        *last = element;
        last ++;
    }
}

template <typename T>
T* MyVector<T>::begin() {
    return first;
}

template <typename T>
T* MyVector<T>::end() {
    return last;
}


#endif //UNTITLED_MYVECTOR_H
