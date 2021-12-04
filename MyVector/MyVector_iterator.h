//
// Created by 原显智 on 2021/12/2.
//

#ifndef UNTITLED_MYVECTOR_ITERATOR_H
#define UNTITLED_MYVECTOR_ITERATOR_H


#include <iostream>
using namespace std;


// step2 class iterator deleted
// step3 const to be added?? when and where to add const??
// whether return by reference when downsize;
// when should keyword inline be used.
/**
 * 1. define data member as three iterators (pointers), first, last, end_of_vector;
 * 2. intuitively, start with an array of elements T and size of the array.
 *
 *
 * */

    template <typename T>
    class MyVector_iterator {

    public:

        MyVector_iterator(void);
        MyVector_iterator(const MyVector_iterator<T> & from); // copy constructor
        MyVector_iterator& operator = (const MyVector_iterator<T> & from);
        ~MyVector_iterator();

        inline int length() const {return last-first; }; // 'Redefinition of 'size' as a different kind of symbol '
        void resize();
        void sizedown();
        void push_back(const T element);
        T& pop_back();

        T& operator[](int t) { // 需不需要throw. 或许会给，方便debug??
            if( (first + t) >= end_of_vector) {
                throw("[] out of range");
            }
            return *(first+t);
        }

    public:

        class iterator {

        public:
            typedef T value_type;
            typedef int64_t difference_type;
            typedef T* pointer;
            typedef T& reference;
            typedef random_access_iterator_tag iterator_category;

            iterator(T* pointer) {
                vector_ptr = pointer;
            };

            bool operator ==(iterator& cmp) {return cmp.vector_ptr == vector_ptr; };
            bool operator !=(iterator& cmp) {return cmp.vector_ptr != vector_ptr; };
            bool operator>=(iterator& rhs) {return vector_ptr >= rhs.vector_ptr;};
            bool operator<(iterator& rhs) {return vector_ptr < rhs.vector_ptr;};
            bool operator<=(iterator& rhs) {return vector_ptr <= rhs.vector_ptr;};
            bool operator>(iterator& rhs) {return vector_ptr > rhs.vector_ptr;};

            iterator& operator++() {vector_ptr++; return *this; };
            iterator& operator--() {vector_ptr--; return *this; };
            iterator operator++(int t) {iterator temp = *this; vector_ptr++; return temp;};
            iterator operator--(int t) {iterator temp = *this; vector_ptr--; return temp;};

            iterator& operator+(int t) {vector_ptr+=t; return *this;};
            iterator& operator-(int t) {vector_ptr-=t; return *this;};
            iterator& operator+=(int t) {vector_ptr+=t; return *this;};
            iterator& operator-=(int t) {vector_ptr-=t; return *this;};

            difference_type operator-(iterator& cmp) {vector_ptr - cmp.vector_ptr;};


            T& operator*() { return *vector_ptr; };
            T* operator->() { return vector_ptr; };

        private:
            T* vector_ptr;

        };

        iterator begin() const {return iterator(first); };
        iterator end() const {return iterator(last); };

    private:
        T* first;
        T* last; // last denotes the address of the next element.
        // thus, when initialized, last == first; resize() is called when last == enf_of_vector;
        T* end_of_vector;

        void vector_init(const int sz);
        void copy_vector(T* const from, T* const to, int num);
    };



    template <typename T>
    void MyVector_iterator<T>::vector_init(const int sz) {
        first = new T[sz];
        last = first;
        end_of_vector = first+sz;
    }

    template <typename T>
    MyVector_iterator<T>::MyVector_iterator(void) {
       vector_init(7);
    }

    template <typename T>
    void MyVector_iterator<T>::copy_vector(T* const from, T* const to, int num) {
        T* traverse_from = from;
        T* traverse_to = to;
        for(int i = 0; i < num; ++i) {
            *traverse_to = *traverse_from;
            traverse_to++;
            traverse_from++;
        }
    }


    template <typename T>
    MyVector_iterator<T>::MyVector_iterator(const MyVector_iterator<T>& from) {
        int sz = from.length();
        vector_init(sz);
        copy_vector(from.first,first, sz);
        last = first + sz;
        // copy the elements
    }

    template <typename T>
    MyVector_iterator<T>& MyVector_iterator<T>::operator= (const MyVector_iterator<T>& from) {
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
    MyVector_iterator<T>::~MyVector_iterator<T>() {
        delete[] first;
    }

    template <typename T>
    void MyVector_iterator<T>::resize() {
        T* old_first = first;
        int old_length = this->length();
        vector_init(2*old_length);

        copy_vector(old_first, first, old_length);
        last = first + old_length;
        delete[] old_first;
    }

    template <typename T>
    void MyVector_iterator<T>::sizedown() {
        int len = this->length();
        T* old_first = first;
        vector_init(2*len);
        copy_vector(old_first,first,len);
        delete[] old_first;
        last = first + len;
    }

    template <typename T>
    void MyVector_iterator<T>::push_back(const T element) {
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
    T& MyVector_iterator<T>::pop_back() {

        int len = this->length();
        if( 4 * len < end_of_vector - first) {
            sizedown();
            std::cout <<  "size down" << std::endl;
        }
        last--;
        return *last;
    }

    /**
    template <typename T>
    MyVector_iterator<T>::iterator MyVector_iterator<T>::begin() const {
        return iterator(first);
    }

    template <typename T>
    iterator MyVector_iterator<T>::end() const {
        return iterator(last);
    }*/




#endif //UNTITLED_MYVECTOR_ITERATOR_H
