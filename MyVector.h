//
// Created by 原显智 on 2021/12/1.
//

#ifndef UNTITLED_MYVECTOR_H
#define UNTITLED_MYVECTOR_H

#include <iostream>

using namespace std;

// step2 class iterator deleted
// step3 const to be added?? when and where to add const??
// whether return by reference when downsize;
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
    MyVector(const MyVector<T> & from); // copy constructor
    MyVector& operator = (const MyVector<T> & from);
    ~MyVector();

    inline int length() const {return last-first; }; // 'Redefinition of 'size' as a different kind of symbol '
    void resize();
    void sizedown();
    void push_back(const T element);
    T& pop_back();

    MyVector::iterator begin();
    MyVector::iterator end();

    //T& operator[](int t) {

    //};

private:
    iterator first;
    iterator last; // last denotes the address of the next element.
    // thus, when initialized, last == first; resize() is called when last == enf_of_vector;
    iterator end_of_vector;

    void vector_init(const int sz);
    void copy_vector(const iterator from, const iterator to, int num);
};

template <typename T>
void MyVector<T>::vector_init(const int sz) {
    first = new T[sz];
    last = first;
    end_of_vector = first+sz;
}

template <typename T>
MyVector<T>::MyVector(void) {
    vector_init(7);
}

template <typename T>
void MyVector<T>::copy_vector(const iterator from, const iterator to, int num) {
    iterator traverse_from = from;
    iterator traverse_to = to;
    for(int i = 0; i < num; ++i) {
        *traverse_to = *traverse_from;
        traverse_to++;
        traverse_from++;
    }
}


template <typename T>
MyVector<T>::MyVector(const MyVector<T>& from) {
    int sz = from.length();
    vector_init(sz);
    copy_vector(from.first,first, sz);
    last = first + sz;
    // copy the elements
}

template <typename T>
MyVector<T>& MyVector<T>::operator= (const MyVector<T>& from) {
    if(this == &from) {
        return *this;
    }else {
        delete[] first; // destruction of element T would be called here;
        int len = from.length();
        vector_init(len);
        copy_vector(from.first,first,len);
        last = first + len;
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
    int old_length = this->length();
    vector_init(2*old_length);

    copy_vector(old_first, first, old_length);
    last = first + old_length;
    delete[] old_first;
}

template <typename T>
void MyVector<T>::sizedown() {
    int len = this->length();
    iterator old_first = first;
    vector_init(2*len);
    copy_vector(old_first,first,len);
    delete[] old_first;
    last = first + len;
}

template <typename T>
void MyVector<T>::push_back(const T element) {
    if(last == end_of_vector) {
        resize();
        std::cout<< "resize" <<std::endl;
        push_back(element);
    }
    else {
        *last = element;
        last ++;
    }
}

template <typename T>
T& MyVector<T>::pop_back() {

    int len = this->length();
    if( 4 * len < end_of_vector - first) {
        sizedown();
        std::cout <<  "size down" << std::endl;
    }
    last--;
    return *last;
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
