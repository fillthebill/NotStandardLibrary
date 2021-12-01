//
// Created by 原显智 on 2021/12/1.
//

#ifndef UNTITLED_MYVECTOR_H
#define UNTITLED_MYVECTOR_H


/**
 * 1. define data member as three iterators (pointers), first, last, end_of_vector;
 * 2.
 *
 *
 * */


template <typename T>
class MyVector {

private:
    T[] vector_data[];
    int size;

public:
    typedef T* iterator;

    MyVector(void);
    MyVector(MyVector<T> & from); // copy constructor
    MyVector& operator = (MyVector<int> & from);
    ~MyVector();

    inline int size() {return size; }; //
    void push_back(T element);
    T& pop_back();

    MyVector::iterator begin();
    MyVector::iterator end();

    T& operator[](int t) {

    };

//
//    class iterator {
// public:
//        T operator*() {
//            return *pointer2T;
//        }
//
//        T& operator++() {
//            pointer2T+=sizeof(T);
//            return *pointer2T;
//        }
//        T& operator+(int t) {
//            pointer2T+=t * sizeof(T);
//            return *pointer2T;
//        }
//
//    private:
//        T* pointer2T;
//    };


};

template <typename T>
MyVector<T>::MyVector(void) {
    vector_data = new T[8];
    size = 0;

}

template <typename T>
MyVector<T>::iterator MyVector::begin() {

}


#endif //UNTITLED_MYVECTOR_H
